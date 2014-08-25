//
//  Camera.cpp
//  IntoSpace
//
//  Created by 李翌文 on 14-8-24.
//
//

#include "Camera.h"
#include "GlobalConfig.h"

SceneCamera* SceneCamera::_instance = nullptr;

SceneCamera::SceneCamera(void)
{
    _start = Vec2(0, 0);
    _prevBlock = Vec2(0, 0);
    _block = Vec2(0, 0);
    _prevCenter = Vec2(0, 0);
    _center = Vec2(0, 0);
    _cameraView = Rect(0, 0, GlobalConfig::scene_width, GlobalConfig::scene_height);
    _cameraCutView = Rect(0, 0, GlobalConfig::scene_width * 2, GlobalConfig::scene_height * 2);
}

SceneCamera::~SceneCamera(void)
{
}

SceneCamera* SceneCamera::getInstance()
{
    if(!_instance)
    {
        _instance = new SceneCamera();
    }
    return _instance;
}

void SceneCamera::setScene(SpaceScene *scene)
{
    if(scene)
    {
        _scene = scene;
    }
}

void SceneCamera::focusOn(BasicObject *obj)
{
    if(obj)
    {
        obj->setFocused(true);
        _focus = obj;
        
        obj->setNormalizedPosition(Vec2(.5f, .5f));
    }
}

void SceneCamera::update(double delta)
{
    if(_center.x == _prevCenter.x && _center.y == _prevCenter.y)
    {
        return;
    }
    
    if(_focus)
    {
        setStart(
                 _focus->getWorldPositionX() - (GlobalConfig::scene_width >> 1),
                 _focus->getWorldPositionY() - (GlobalConfig::scene_height >> 1));
    }
    
    _cameraView.setRect(
                        _start.x,
                        _start.y,
                        _cameraView.size.width,
                        _cameraView.size.height);
}

void SceneCamera::setStart(float x, float y)
{
    if(x < 0)
    {
        _start.x = x + GlobalConfig::block_width;
    }
    else if(x > GlobalConfig::block_width)
    {
        _start.x = x - GlobalConfig::block_width;
    }
    else
    {
        _start.x = x;
    }
    
    if(y < 0)
    {
        _start.y = y + GlobalConfig::block_height;
    }
    else if(y > GlobalConfig::block_height)
    {
        _start.y = y - GlobalConfig::block_height;
    }
    else
    {
        _start.y = y;
    }
}