//
//  Camera.h
//  IntoSpace
//
//  Created by 李翌文 on 14-8-24.
//
//

#ifndef __IntoSpace__Camera__
#define __IntoSpace__Camera__

#include "cocos2d.h"
#include "BasicObject.h"
#include "SpaceScene.h"

USING_NS_CC;

class SceneCamera
{
public:
    static SceneCamera* getInstance();
    void setStart(double x, double y);
    void setBlock(int x, int y);
    void setCutStart(double x, double y);
	float getViewStartX() { return _start.x; };
	float getViewStartY() { return _start.y; };
	float getCutViewStartX() { return _cutStart.x; };
	float getCutViewStartY() { return _cutStart.y; };
    void setScene(SpaceScene* scene);
    void focusOn(BasicObject *obj);
    Rect& getCameraView();
    Rect& getCameraCutView();
    void update(double delta);
    Vec2 getScreenPosition(double positionX, double positionY, int blockX, int blockY);
private:
    SceneCamera(void);
    ~SceneCamera(void);
    
    static SceneCamera* _instance;
    
	Vec2 _cutStart;
    Vec2 _start;
    Vec2 _cutBlock;
    Vec2 _block;
    Rect _cameraView;
    Rect _cameraCutView;
    double _x;
    double _y;
    BasicObject* _focus;
    SpaceScene* _scene;
};

#endif /* defined(__IntoSpace__Camera__) */
