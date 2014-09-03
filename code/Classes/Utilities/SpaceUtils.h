#ifndef _SPACEUTILS_H_
#define _SPACEUTILS_H_
#pragma once

#include "cocos2d.h"

#define AU 149597870700
#define KM_TRIGGER 9999
#define KM 1000

USING_NS_CC;

class SpaceUtils
{
public:
	static std::string humanReadableDistance(unsigned long long distance);
};

#endif
