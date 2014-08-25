#ifndef _BASICOBJECT_H_
#define _BASICOBJECT_H_

#include "cocos2d.h"

#pragma once

USING_NS_CC;
class Behavior;
class BasicObject :
	public Sprite
{
public:
	const char* getGuid();
	void setBlock(int x, int y);
	void setWorldPosition(float x, float y);
    float getWorldPositionX()
    {
        return _positionX;
    };
    float getWorldPositionY()
    {
        return _positionY;
    };
    void setFocused(bool);
    bool isFocused();
    virtual void update(double delta);

private:
	const char* guid;

	int _blockX;				//«¯øÈX
	int _blockY;				//«¯øÈY
	float _positionX;				//‘⁄µ±«∞«¯øÈ÷–µƒŒª÷√X
	float _positionY;				//‘⁄µ±«∞«¯øÈ÷–µƒŒª÷√Y
    bool _isFocused;            //是否是镜头焦点

protected:
	BasicObject(void);
	~BasicObject(void);
};

#endif
