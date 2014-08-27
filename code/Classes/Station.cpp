//
//  Station.cpp
//  IntoSpace
//
//  Created by 李翌文 on 14-8-26.
//
//

#include "Station.h"
#include "Render/StaticRender.h"

Station::Station(void):BasicObject()
{
    setMainRender(new StaticRender());
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
		setSpriteFrame(SpriteFrame::create("images/stations/space_station_blue.png", Rect(0, 0, 1024, 577)));
		return true;
	}
	return false;
}
