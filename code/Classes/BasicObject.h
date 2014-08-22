#include "cocos2d.h"

#pragma once

USING_NS_CC;
class BasicObject :
	public Sprite
{
public:
	const char* getGuid();
	void setBlock(int x, int y);
	void setPosition(int x, int y);

private:
	const char* guid;

	int _blockX;				//����X
	int _blockY;				//����Y
	int _positionX;				//�ڵ�ǰ�����е�λ��X
	int _positionY;				//�ڵ�ǰ�����е�λ��Y

protected:
	BasicObject(void);
	~BasicObject(void);
};

