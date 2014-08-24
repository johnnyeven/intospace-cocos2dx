//
//  Behavior.h
//  IntoSpace
//
//  Created by 李翌文 on 14-8-24.
//
//

#ifndef __IntoSpace__Behavior__
#define __IntoSpace__Behavior__

#include "cocos2d.h"

USING_NS_CC;
class BasicObject;
class Behavior
{
public:
    Behavior(void);
    ~Behavior(void);
    
    virtual void update(double delta);
    virtual void installListener();
    virtual void uninstallListener();
    
    void setTarget(BasicObject*);
    BasicObject* getTarget();
protected:
    BasicObject *_target;
};

#endif /* defined(__IntoSpace__Behavior__) */
