#include "SpaceScene.h"
#include "PlayerShip.h"
#include "Camera.h"

USING_NS_CC;

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

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("attack_drone_3_1.plist");

	auto ship = PlayerShip::create();
	addChild(ship);
    
    _player = ship;
    
    SceneCamera::getInstance()->focusOn(ship);

    return true;
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
//        float angle = CC_RADIANS_TO_DEGREES(atan2f(pTouch.y - pPlayer.y, pTouch.x - pPlayer.x));
        
        _player->setTargetDirection(pTouch.x - pPlayer.x, pTouch.y - pPlayer.y);
//        log("%f", angle);
    }
    return true;
}

void SpaceScene::update(float delta)
{
    if(_player)
    {
        _player->update(delta);
    }
}
