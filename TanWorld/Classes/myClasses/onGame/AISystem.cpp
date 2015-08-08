#include "AISystem.h"


AISystem::AISystem(cocos2d::Layer* targetLayer)
:m_battleLand(targetLayer)
{

}

AISystem::~AISystem()
{

}

void AISystem::initTanksInScene(std::vector<Vec2> _positions)
{
	for (auto pos : _positions)
	{
		addRobot(pos);
	}
}

void AISystem::addRobot(Vec2 _pos)
{
	auto robot = EnemyTank::create(enemyPath);
	m_battleLand->addChild(robot);
	robot->setPosition(_pos);
	robot->getPhysicsBody()->setTag(ENEMY_TAG);
	robot->AIStart();

	m_robots.push_back(robot);
}

std::vector<EnemyTank*> AISystem::getAllEnemies()
{
	return m_robots;
}

bool AISystem::removeAllEnemies()
{
	for (auto& robot : m_robots)
	{
		robot->removeFromParentAndCleanup(true);
	}
	return true;
}