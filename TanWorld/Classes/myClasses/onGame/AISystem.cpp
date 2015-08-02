#include "AISystem.h"


AISystem::AISystem(cocos2d::Layer* targetLayer)
:m_battleLand(targetLayer)
{

}

AISystem::~AISystem()
{

}

void AISystem::initTanksInScene()
{

}

void AISystem::addRobot()
{
	auto robot = EnemyTank::create(enemyPath);
	m_battleLand->addChild(robot);
}