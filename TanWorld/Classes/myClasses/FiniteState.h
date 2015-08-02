#ifndef __State_H__
#define __State_H__

#include "cocos2d.h"

USING_NS_CC;

//#define		

enum AIState{
	AI_BEING_ATTACK,
	AI_BLOCKED,
	AI_SEARCHING_ENEMY
};

class FiniteState
{
private:
	float						RantoFind;			//
	AIState						currentState;		//µ±Ç°×´Ì¬
public:
	float getRantoFind();

	bool init();

	virtual bool isPlayerFound() = 0;
	bool isRest();

	virtual void FindPlayer() = 0;
	virtual void Patrol() = 0;
	virtual void Rest() = 0;

	virtual bool RanWantFindPlayer(float RantoFind) = 0;

	void FiniteStateRun();

	void changeState(AIState  curS);

protected:
	FiniteState();
	~FiniteState();
};

#endif  //__State_H__