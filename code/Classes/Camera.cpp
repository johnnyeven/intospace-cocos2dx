//
//  Camera.cpp
//  IntoSpace
//
//  Created by 李翌文 on 14-8-24.
//
//

#include "Camera.h"

SceneCamera* SceneCamera::_instance = nullptr;

SceneCamera::SceneCamera(void)
{
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