#include "cocos2d.h"

#pragma once

USING_NS_CC;
class BasicObject :
	public Sprite
{
public:
	BasicObject(void);
	~BasicObject(void);
	
	const char* getGuid();
	void setBlock(int x, int y);
	void setPosition(int x, int y);

private:
	const char* guid;

protected:
	int _blockX;				//区块X
	int _blockY;				//区块Y
	int _positionX;				//在当前区块中的位置X
	int _positionY;				//在当前区块中的位置Y
};

