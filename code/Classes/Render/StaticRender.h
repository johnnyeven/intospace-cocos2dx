//
//  StaticRender.h
//  IntoSpace
//
//  Created by 李翌文 on 14-8-27.
//
//

#ifndef __IntoSpace__StaticRender__
#define __IntoSpace__StaticRender__

#include "cocos2d.h"
#include "BasicObject.h"
#include "Camera.h"
#include "GlobalConfig.h"

USING_NS_CC;

class StaticRender:
    public IRender
{
public:
    StaticRender(void);
    virtual ~StaticRender(void);
	virtual void update(double delta);
	virtual Node* getTarget();
	virtual void setTarget(Node*);
private:
    BasicObject* _target;
};

#endif /* defined(__IntoSpace__StaticRender__) */
