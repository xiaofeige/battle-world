#include "chapter1.h"
#include "../../GameHandleLib.h"

Chapter1::Chapter1()
{
	//set chapter_no
	m_chapterNo = 1;
}
Chapter1::~Chapter1()
{

}


bool Chapter1::init()
{
	if (!BaseLayer::init())
		return false;

	//add your init code below...
	
	m_map = CSLoader::createNode("tankWorldBg/tankWorldBg.csb");
	if (m_map)
	{
		m_map->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
		m_map->setPosition(Vec2(0, 0));
		this->addChild(m_map);
		m_map->setZOrder(0);
		//设置层号  z-order
		std::string		nodeName = "roads";
		auto  roads = seekFromRootByName(m_map, nodeName);
		roads->setGlobalZOrder(-1);
		nodeName = "trees";
		auto trees = seekFromRootByName(m_map, nodeName);
		trees->setGlobalZOrder(5);
		trees->setOpacity(245);

		//障碍物添加刚体
		nodeName = "houses";
		auto housesNode = seekFromRootByName(m_map, nodeName);
		auto houses = housesNode->getChildren();

		for (auto& house : houses)
		{
			if (typeid(*house) == typeid(Sprite))
			{
				auto houseBody = PhysicsBody::createBox(house->getContentSize());
				houseBody->setTag(MAP_BARRIAR_TAG);
				houseBody->setDynamic(false);
				houseBody->setContactTestBitmask(UNITIVE_MASK);
				house->setPhysicsBody(houseBody);
			}
		}

		//给湖泊添加刚体
		nodeName = "pools";
		auto poolNode = seekFromRootByName(m_map,nodeName);
		auto pools = poolNode->getChildren();
		for (auto& pool : pools)
		{
			if (typeid(*pool) == typeid(Sprite))
			{
				auto spriteScaleX = pool->getScaleX();
				auto spriteScaleY = pool->getScaleY();
				auto bodySize = cocos2d::Size(pool->getContentSize().width*spriteScaleX, pool->getContentSize().height*spriteScaleY);
				auto poolBody = PhysicsBody::createBox(bodySize);
				poolBody->setTag(MAP_POOL_TAG);
				poolBody->setDynamic(false);
				poolBody->setContactTestBitmask(POOL_MASK);
				pool->setPhysicsBody(poolBody);
			}
		}
	}
	
	
	//添加机器人
	m_AIManager.addRobot(Vec2(100, 100));
	m_AIManager.addRobot(Vec2(200, 100));
	m_AIManager.addRobot(Vec2(300, 100));
	m_AIManager.addRobot(Vec2(400, 100));

	return true;
}

