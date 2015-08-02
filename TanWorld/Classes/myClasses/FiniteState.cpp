#include "FiniteState.h"

bool State::isRest()
{
	return true;
}

bool State::RanWantFindPlayer(float RantoFind)
{
	//��RantoFind�ĸ���ȥѰ�ҵ���
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
		//Ѱ�ҵ���
		if (isRest())
		{
			Rest();
			changeState(StateRest);
		}
		//�л�����Ϣ״̬
		break;

	case AI_REST:
		//��������
		if (isRest())
		{
			Rest();
			changeState(StateRest);
		}
		//�л�����Ϣ״̬
		break;
	case AI_PATROL:
		//������Ѱ�ҵ��˻�Ѳ��
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