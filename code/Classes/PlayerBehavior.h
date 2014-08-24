//
//  PlayerBehavior.h
//  IntoSpace
//
//  Created by 李翌文 on 14-8-24.
//
//

#ifndef __IntoSpace__PlayerBehavior__
#define __IntoSpace__PlayerBehavior__

#include "cocos2d.h"
#include "Behavior.h"
#include "PlayerShip.h"

USING_NS_CC;
class PlayerBehavior: public Behavior
{
public:
    PlayerBehavior(void);
    ~PlayerBehavior(void);
    
    virtual void update(double delta);
    virtual void installListener();
    virtual void uninstallListener();
    
    void setTurnSpeed(float);
    float getTurnSpeed();
    void setTargetDegrees(float);
    float getTargetDegrees();
    void setTarget(PlayerShip*);
    PlayerShip* getTarget();
private:
    PlayerShip *_target;
    float _targetDegrees;   //要转向的角度
    float _turnSpeed;       //转向速度
};

#endif /* defined(__IntoSpace__PlayerBehavior__) */
