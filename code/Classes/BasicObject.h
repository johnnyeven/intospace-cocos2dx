#ifndef _BASICOBJECT_H_
#define _BASICOBJECT_H_

#include "cocos2d.h"
#include "Render/IRender.h"

#pragma once

USING_NS_CC;
class Behavior;
class BasicObject :
	public Sprite
{
public:
	const char* getGuid();
	void setBlock(int x, int y);
	Vec2 getBlock() { return Vec2(_blockX, _blockY); };
	void setWorldPosition(double x, double y);
    double getWorldPositionX()
    {
        return _positionX;
    };
    double getWorldPositionY()
    {
        return _positionY;
    };
    void setFocused(bool);
    bool isFocused();
    virtual void update(double delta);
	void addRender(IRender*);
	void setMainRender(IRender*);
    void setIsRemain(bool);
    bool isRemain();
	
	float zIndex;					//层级，影响视距感
private:
	const char* guid;

	int _blockX;				//区块X
	int _blockY;				//区块Y
	double _positionX;			//世界坐标X
	double _positionY;			//世界坐标Y
    bool _isFocused;            //是否是镜头焦点
    bool _isRemain;             //是否一直保留
	
	IRender* _mainRender;
	std::vector<IRender*> _renders;

protected:
	BasicObject(void);
	~BasicObject(void);
};

#endif
