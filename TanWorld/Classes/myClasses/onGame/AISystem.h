#ifndef __AI_SYSTEM_H__
#define __AI_SYSTEM_H__

#include "cocos2d.h"
#include "..\Tank.h"
#include "..\GameResource.h"

/*-------------------------------------------------------------------------------------
*CLASS NAME: £Á£É£Ó£ù£ó£ô£å£í
£ªDESC£º	controll all the robots in a scene, to add, to delete, and to set the robot where
		it should be.
---------------------------------------------------------------------------------------*/
class AISystem
{
public:
	AISystem(cocos2d::Layer* targetLayer);
	~AISystem();

	//set several tanks in visible horizons
	//para: some points to set enemy tanks
	void			initTanksInScene(std::vector<Vec2> _positions);

	//DESC: add robot into scene
	//para:	postion of the robot when added to the scene
	void			addRobot(Vec2 _pos);

	//DESC::
	//return:	pointers of all the enemies
	std::vector<EnemyTank*>		getAllEnemies();

	//DESC:
	//return: true if remove succeed,or false if not
	bool						removeAllEnemies();
	
private:
	std::vector<EnemyTank*>		m_robots;			//all the enemies
	cocos2d::Layer*				m_battleLand;		//battle land
};

#endif //__AI_SYSTEM_H__