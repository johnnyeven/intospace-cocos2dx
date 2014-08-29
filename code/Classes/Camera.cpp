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
	_cutStart = Vec2(0, 0);
    _start = Vec2(0, 0);
    _cutBlock = Vec2(0, 0);
    _block = Vec2(0, 0);
    _cameraView = Rect(0, 0, GlobalConfig::scene_width, GlobalConfig::scene_height);
    _cameraCutView = Rect(0, 0, GlobalConfig::scene_width * 3, GlobalConfig::scene_height * 3);
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
    if(!_focus)
    {
        return;
    }
    
    setBlock(_focus->getBlock().x, _focus->getBlock().y);
    setCutStart(_block.x, _block.y);
    
    setStart(
				_focus->getWorldPositionX() - (GlobalConfig::scene_width >> 1),
				_focus->getWorldPositionY() - (GlobalConfig::scene_height >> 1));

    setCutStart(
				_start.x - GlobalConfig::scene_width,
                _start.y - GlobalConfig::scene_height);
    
    _cameraView.setRect(
                        _start.x,
                        _start.y,
                        _cameraView.size.width,
                        _cameraView.size.height);

	_cameraCutView.setRect(
						_cutStart.x,
						_cutStart.y,
						_cameraCutView.size.width,
						_cameraCutView.size.height);
}

void SceneCamera::setBlock(int x, int y)
{
    _block.x = x;
    _block.y = y;
}

void SceneCamera::setStart(double x, double y)
{
    if(x < 0)
    {
        _start.x = x + GlobalConfig::block_width;
        --_block.x;
    }
    else if(x > GlobalConfig::block_width)
    {
        _start.x = x - GlobalConfig::block_width;
        ++_block.x;
    }
    else
    {
        _start.x = x;
    }
    
    if(y < 0)
    {
        _start.y = y + GlobalConfig::block_height;
        --_block.y;
    }
    else if(y > GlobalConfig::block_height)
    {
        _start.y = y - GlobalConfig::block_height;
        ++_block.y;
    }
    else
    {
        _start.y = y;
    }
}

void SceneCamera::setCutStart(double x, double y)
{
    if(x < 0)
    {
        _cutStart.x = x + GlobalConfig::block_width;
        --_cutBlock.x;
    }
    else if(x > GlobalConfig::block_width)
    {
        _cutStart.x = x - GlobalConfig::block_width;
        ++_cutBlock.y;
    }
    else
    {
        _cutStart.x = x;
    }
    
    if(y < 0)
    {
        _cutStart.y = y + GlobalConfig::block_height;
        --_cutBlock.y;
    }
    else if(y > GlobalConfig::block_height)
    {
        _cutStart.y = y - GlobalConfig::block_height;
        ++_cutBlock.y;
    }
    else
    {
        _cutStart.y = y;
    }
}

Vec2 SceneCamera::getScreenPosition(double positionX, double positionY, int blockX, int blockY)
{
	double _x = positionX + (blockX - _block.x) * GlobalConfig::block_width;
	double _y = positionY + (blockY - _block.y) * GlobalConfig::block_height;
	double _screenX = _start.x;
	double _screenY = _start.y;
	return Vec2(
				_x - _screenX,
				_y - _screenY);
}