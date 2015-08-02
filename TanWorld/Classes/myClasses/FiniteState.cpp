#include "FiniteState.h"

bool State::isRest()
{
	return true;
}

bool State::RanWantFindPlayer(float RantoFind)
{
	//有RantoFind的概率去寻找敌人
	float ran = CCRANDOM_0_1();
	if (ran < RantoFind)
	{
		return true;
	}
	return false;
}

float State::getRantoFind()
{
	return RantoFind;
}

void State::changeState(AIState curS)
{
	this->currentState = curS;
}

void State::update()
{
	switch (currentState)
	{
	case AI_FIND_PLAYER:
		//寻找敌人
		if (isRest())
		{
			Rest();
			changeState(StateRest);
		}
		//切换到休息状态
		break;

	case AI_REST:
		//来回行走
		if (isRest())
		{
			Rest();
			changeState(StateRest);
		}
		//切换到休息状态
		break;
	case AI_PATROL:
		//按概率寻找敌人或巡逻
		if (RanWantFindPlayer(getRantoFind()))
		{
			FindPlayer();
			changeState(StateFindPlayer);
		}
		else
		{
			Patrol();
			changeState(StatePatrol);
		}
		break;
	}
}