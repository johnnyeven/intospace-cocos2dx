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
    
    void setScene(SpaceScene* scene);
    void focusOn(BasicObject *obj);
private:
    SceneCamera(void);
    ~SceneCamera(void);
    
    static SceneCamera* _instance;
    
    Rect* _cameraView;
    double _x;
    double _y;
    BasicObject* _focus;
    SpaceScene* _scene;
};

#endif /* defined(__IntoSpace__Camera__) */
