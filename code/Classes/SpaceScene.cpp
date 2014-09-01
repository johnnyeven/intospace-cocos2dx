#include "SpaceScene.h"
#include "PlayerShip.h"
#include "Station.h"
#include "Camera.h"
#include "Render/SpaceStarRender.h"
#include "json/rapidjson.h"
#include "json/document.h"
#include <functional>

USING_NS_CC;
using namespace rapidjson;

Scene* SpaceScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = SpaceScene::create();
    SceneCamera::getInstance()->setScene(layer);

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SpaceScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(SpaceScene::onTouchBegan, this);
    listener->setSwallowTouches(true);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    _objectList = Vector<BasicObject*>();
    _displayList = Vector<BasicObject*>();

	//Create bgLayer
	_bgLayer = Sprite::create();
	_bgLayer->setAnchorPoint(Vec2(0, 0));
	addChild(_bgLayer);

	//Create mainLayer
	_mainLayer = Sprite::create();
	_mainLayer->setAnchorPoint(Vec2(0, 0));
	addChild(_mainLayer);

	//Create effectLayer
	_effectLayer = Sprite::create();
	_effectLayer->setAnchorPoint(Vec2(0, 0));
	addChild(_effectLayer);

	//Create main Ship
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("images/ships/attack_drone_3_1.plist");

	auto ship = PlayerShip::create();
    
    _player = ship;
	
	_player->setMaxVelocity(1000.f);
    
    SceneCamera::getInstance()->focusOn(ship);
    SceneCamera::getInstance()->update(0);
    
	//Create map
	loadMap("config/maps/A-1-2.json");
    
	addChild(ship);

	_renders = std::vector<IRender*>();
	addRender(new SpaceStarRender());

    return true;
}

bool SpaceScene::loadMap(const std::string& mapId)
{
	if(mapId.size() > 0)
	{
		Document doc;
		if(FileUtils::getInstance()->isFileExist(mapId))
		{
			std::string json = FileUtils::getInstance()->getStringFromFile(mapId);
			doc.Parse<rapidjson::kParseDefaultFlags>(json.c_str());
			if(!doc.HasParseError())
			{
				if(doc.IsObject())
				{
					if(doc.HasMember("mapPListFilePath") && doc.HasMember("spriteFrameName"))
					{
						std::string mapFilePath = doc["mapPListFilePath"].GetString();
						std::string spriteFrameName = doc["spriteFrameName"].GetString();
						SpriteFrameCache::getInstance()->addSpriteFramesWithFile(mapFilePath);
						_bgLayer->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameName));
					}
					if(doc.HasMember("stations"))
					{
						const rapidjson::Value& stations = doc["stations"];
						if(stations.IsArray())
						{
							int size = stations.Size();
							for(int i = 0; i < size; ++i)
							{
								const rapidjson::Value& station = stations[i];
								if(station.IsObject() &&
									station.HasMember("resource") &&
									station.HasMember("zIndex") &&
									station.HasMember("blockX") &&
									station.HasMember("blockY") &&
									station.HasMember("positionX") &&
									station.HasMember("positionY"))
								{
									auto s = Station::create(station["resource"].GetString());
									s->zIndex = station["zIndex"].GetDouble();
									s->setBlock(station["blockX"].GetInt(), station["blockY"].GetInt());
									s->setWorldPosition(station["positionX"].GetInt(), station["positionY"].GetInt());
									addDisplay(s);
								}
							}
						}
					}
				}
			}
			else
			{
				log("GetParserError %s\n", doc.GetParseError());
			}
		}
		else
		{
			log("file not exist");
		}
	}
	return false;
}

void SpaceScene::onEnter()
{
    Layer::onEnter();
    scheduleUpdate();
}

bool SpaceScene::onTouchBegan(Touch *touch, Event *event)
{
    Vec2 pTouch = touch->getLocation();
    
    if(_player)
    {
        Vec2 pPlayer = _player->getPosition();
        _player->setTargetDirection(pTouch.x - pPlayer.x, pTouch.y - pPlayer.y);
		
		_player->setAcceleration(30.f);
		_player->setAction(ShipAction::MOVE);
    }
    return true;
}

void SpaceScene::update(float delta)
{
    SceneCamera::getInstance()->update(delta);
    
    if(_player)
    {
        _player->update(delta);
    }

	int size = _renders.size();
	for(int i = 0; i < size; ++i)
	{
		_renders.at(i)->update(delta);
	}

	std::sort(_displayList.begin(), _displayList.end(), std::greater<BasicObject*>());
	size = _displayList.size();
	while(size--)
	{
		auto item = _displayList.at(size);
		item->setLocalZOrder(size);
	}
    
    size = _objectList.size();
    for(int i = 0; i < size; ++i)
    {
        auto obj = _objectList.at(i);
        if(isInScene(obj))
        {
            addRenderList(obj);
        }
        else
        {
            removeRenderList(obj);
        }
        if(_displayList.getIndex(obj) >= 0)
        {
            obj->update(delta);
        }
    }
}

void SpaceScene::addRender(IRender* render)
{
	render->setTarget(this);
	_renders.push_back(render);
}

PlayerShip* SpaceScene::getPlayer()
{
	return _player;
}

bool SpaceScene::isInScene(BasicObject *obj)
{
    auto camera = SceneCamera::getInstance();
    Rect view = camera->getScreenCutView();
    Vec2 p = camera->getScreenPosition(
                                       obj->getWorldPositionX(),
                                       obj->getWorldPositionY(),
                                       obj->getBlock().x,
                                       obj->getBlock().y);
    if(obj->zIndex > 0)
    {
        //修正视距差效果
        p.x = p.x * obj->zIndex + (GlobalConfig::scene_width >> 1);
        p.y = p.y * obj->zIndex + (GlobalConfig::scene_height >> 1);
    }
    
    return view.containsPoint(p);
}

void SpaceScene::addDisplay(BasicObject * obj)
{
    if(_objectList.getIndex(obj) == -1)
    {
        _objectList.pushBack(obj);
        
        if(isInScene(obj))
        {
            addRenderList(obj);
        }
    }
}

void SpaceScene::removeDisplay(BasicObject *obj)
{
    int i = _objectList.getIndex(obj);
    if(i >= 0)
    {
        Vector<BasicObject*>::iterator it = _objectList.begin() + i;
        _objectList.erase(it);
        
        removeRenderList(obj);
    }
}

void SpaceScene::addRenderList(BasicObject *obj)
{
    if(_displayList.getIndex(obj) == -1)
    {
        _displayList.pushBack(obj);
        _mainLayer->addChild(obj);
        log("add into renderlist");
    }
}

void SpaceScene::removeRenderList(BasicObject *obj)
{
    int i = _displayList.getIndex(obj);
    if(i >= 0)
    {
        Vector<BasicObject*>::iterator it = _displayList.begin() + i;
        _displayList.erase(it);
        _mainLayer->removeChild(obj, true);
        log("remove from renderlist");
    }
}