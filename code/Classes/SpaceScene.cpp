#include "SpaceScene.h"
#include "PlayerShip.h"

USING_NS_CC;

Scene* SpaceScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = SpaceScene::create();

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

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("attack_drone_1_1.plist");

	auto ship = PlayerShip::create();
	ship->setNormalizedPosition(ccp(.5f, .5f));
	addChild(ship);

    return true;
}
