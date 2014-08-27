//
//  Station.h
//  IntoSpace
//
//  Created by 李翌文 on 14-8-26.
//
//

#ifndef __IntoSpace__Station__
#define __IntoSpace__Station__

#include "cocos2d.h"
#include "BasicObject.h"

USING_NS_CC;
class Station: public BasicObject
{
public:
	static Station* create();
	virtual bool init();
private:
    Station(void);
    ~Station(void);
};

#endif /* defined(__IntoSpace__Station__) */
