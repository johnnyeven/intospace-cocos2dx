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
    void setStart(float x, float y);
    void setCutStart(float x, float y);
    float getViewStartX();
    float getViewStartY();
    float getCutViewStartX();
    float getCutViewStartY();
    void setScene(SpaceScene* scene);
    void focusOn(BasicObject *obj);
    Rect& getCameraView();
    Rect& getCameraCutView();
    void update(double delta);
private:
    SceneCamera(void);
    ~SceneCamera(void);
    
    static SceneCamera* _instance;
    
	Vec2 _cutStart;
    Vec2 _start;
    Vec2 _prevBlock;
    Vec2 _block;
    Rect _cameraView;
    Rect _cameraCutView;
    double _x;
    double _y;
    BasicObject* _focus;
    SpaceScene* _scene;
};

#endif /* defined(__IntoSpace__Camera__) */
