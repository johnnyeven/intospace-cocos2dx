#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "BasicObject.h"
#include "PlayerShip.h"
#include "Render/IRender.h"
#include "Identifier/IIdentifier.h"

class SpaceScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    virtual void onEnter();
    virtual void update(float delta);
    virtual bool onTouchBegan(Touch *touch, Event *event);
    
    // implement the "static create()" method manually
    CREATE_FUNC(SpaceScene);

	bool loadMap(const std::string& mapId);
	void addRender(IRender*);
	PlayerShip* getPlayer();
    bool isInScene(BasicObject*);
    void addRenderList(BasicObject*);
    void removeRenderList(BasicObject*);
    void addDisplay(BasicObject*);
    void removeDisplay(BasicObject*);
	void addIdentifier(IIdentifier*);
	void removeIdentifier(IIdentifier*);
    
private:
    PlayerShip* _player;
	std::vector<IRender*> _renders;
	std::vector<IIdentifier*> _identifierList;
    Vector<BasicObject*> _objectList;
    Vector<BasicObject*> _displayList;
	Sprite* _bgLayer;
	Layer* _mainLayer;
	Layer* _effectLayer;
	Layer* _idLayer;
};

#endif // __HELLOWORLD_SCENE_H__
