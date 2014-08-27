//
//  Station.cpp
//  IntoSpace
//
//  Created by 李翌文 on 14-8-26.
//
//

#include "Station.h"

Station::Station(void):BasicObject()
{
    
}

Station::~Station(void)
{
    
}

Station* Station::create()
{
    Station* s = new (std::nothrow) Station();
    if (s && s->init())
    {
        s->autorelease();
        return s;
    }
    CC_SAFE_DELETE(s);
    return nullptr;
}

bool Station::init()
{
	if(BasicObject::init())
	{
		return true;
	}
	return false;
}
