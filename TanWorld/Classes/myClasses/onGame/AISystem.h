#ifndef __AI_SYSTEM_H__
#define __AI_SYSTEM_H__

#include "cocos2d.h"
#include "..\Tank.h"
#include "..\GameResource.h"

class AISystem
{
public:
	AISystem(cocos2d::Layer* targetLayer);
	~AISystem();

	//set five tanks in visible horizons
	void			initTanksInScene();
	//add robot into scene
	void			addRobot();
	
private:
	cocos2d::Layer*				m_battleLand;		//Õ½³¡

};

#endif //__AI_SYSTEM_H__