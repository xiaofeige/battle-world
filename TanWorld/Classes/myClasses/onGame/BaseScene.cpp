#include "BaseScene.h"
#include "extensions/cocos-ext.h"
#include "cocostudio/CocoStudio.h"
#include "../beforeGame/MainMenu.h"

/*---------------------------------------------------------------------------------*/
/*------------------------------class name:BaseLayer--------------------------------*/
/*---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------*/

BaseLayer::BaseLayer()
:m_currentPlayer(nullptr)
,m_AIManager(this)
{
}

BaseLayer::~BaseLayer()
{

}

bool BaseLayer::init()
{
	if (!Layer::init())
		return false;

	//add your init code below...
	//set scene edge to limit the tank out of horizon
	auto visibleSize = VisibleRect::getVisibleRect().size;
	auto edge = Sprite::create();
	auto edgeBox = PhysicsBody::createEdgeBox(visibleSize, PHYSICSSHAPE_MATERIAL_DEFAULT, 1);
	edge->setPhysicsBody(edgeBox);
	edge->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	edge->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(edge);

	//set background music
	this->m_isBgMusicRunning = true;
	SimpleAudioEngine::getInstance()->playBackgroundMusic(LoadingMusicPath, true);

	//set player
	m_currentPlayer = PlayerTank::create(tankImgPath);
	if (m_currentPlayer)
	{
		m_currentPlayer->setPosition(Vec2(100,100));
		this->addChild(m_currentPlayer);
	}


	//load controller
	auto controllerImg = CSLoader::createNode(PlayerControllerPath);
	controllerImg->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	controllerImg->setPosition(VisibleRect::center());
	this->addChild(controllerImg);

	//set move action of button
	std::string buttonName= "Btn_up";
	auto upBtn = seekFromRootByName(controllerImg, buttonName);
	static_cast<Button*>(upBtn)->addTouchEventListener(CC_CALLBACK_2(PlayerTank::move, m_currentPlayer, FTank::TankDirect::TD_UP));
	buttonName = "Btn_right";
	auto rightBtn = seekFromRootByName(controllerImg, buttonName);
	static_cast<Button*>(rightBtn)->addTouchEventListener(CC_CALLBACK_2(PlayerTank::move, m_currentPlayer, FTank::TankDirect::TD_RIGHT));
	buttonName = "Btn_down";
	auto downBtn = seekFromRootByName(controllerImg, buttonName);
	static_cast<Button*>(downBtn)->addTouchEventListener(CC_CALLBACK_2(PlayerTank::move, m_currentPlayer, FTank::TankDirect::TD_DOWN));
	buttonName = "Btn_left";
	auto leftBtn = seekFromRootByName(controllerImg, buttonName);
	static_cast<Button*>(leftBtn)->addTouchEventListener(CC_CALLBACK_2(PlayerTank::move, m_currentPlayer, FTank::TankDirect::TD_LEFT));

	//attack action
	buttonName = "Btn_bullet";
	auto bulletBtn = seekFromRootByName(controllerImg, buttonName);
	static_cast<Button*>(bulletBtn)->addTouchEventListener(CC_CALLBACK_2(PlayerTank::act, m_currentPlayer, PlayerTank::PlayerAction::PA_FIRE_BULLET));
	buttonName = "Btn_bomb";
	auto bombBtn = seekFromRootByName(controllerImg, buttonName);
	static_cast<Button*>(bombBtn)->addTouchEventListener(CC_CALLBACK_2(PlayerTank::act, m_currentPlayer, PlayerTank::PlayerAction::PA_FIRE_BOMB));
	buttonName = "Btn_slide";
	auto slideBtn = seekFromRootByName(controllerImg, buttonName);
	static_cast<Button*>(slideBtn)->addTouchEventListener(CC_CALLBACK_2(PlayerTank::act, m_currentPlayer, PlayerTank::PlayerAction::PA_SLIDE));
	buttonName = "Btn_ultimate";
	auto ultimateBtn = seekFromRootByName(controllerImg, buttonName);
	static_cast<Button*>(ultimateBtn)->addTouchEventListener(CC_CALLBACK_2(PlayerTank::act, m_currentPlayer, PlayerTank::PlayerAction::PA_ULTIMATE));

	//music and quit
	buttonName = "Btn_quit";
	auto quitBtn = seekFromRootByName(controllerImg, buttonName);
	static_cast<Button*>(quitBtn)->addTouchEventListener(CC_CALLBACK_2(BaseLayer::returnToMainScene, this));
	buttonName = "Btn_music";
	auto musicBtn = seekFromRootByName(controllerImg, buttonName);
	static_cast<Button*>(musicBtn)->addTouchEventListener(CC_CALLBACK_2(BaseLayer::turnOnBgMusic, this));

	//set contack listener
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(BaseLayer::contactListen, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

	//
	return true;
}

void BaseLayer::turnOnBgMusic(Ref *pSender, Widget::TouchEventType _touchType)
{
	if (_touchType == Widget::TouchEventType::ENDED)
	{
		if (this->m_isBgMusicRunning)	//if it is running then turn off
		{
			SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
			this->m_isBgMusicRunning = false;
		}
		else //turn on the music
		{
			this->m_isBgMusicRunning = true;
			SimpleAudioEngine::getInstance()->playBackgroundMusic(LoadingMusicPath,true);
		}
	}
}

//pause
void BaseLayer::gamePause(Ref *pSender, Widget::TouchEventType _touchType)
{
	//
	Director::getInstance()->pause();
	SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

//
void BaseLayer::returnToMainScene(Ref *pSender, Widget::TouchEventType _touchType)
{
	auto mainScene = MainMenu::createScene();
	auto transScene = TransitionTurnOffTiles::create(1.0f, mainScene);
	Director::getInstance()->replaceScene(transScene);
}


bool BaseLayer::contactListen(const PhysicsContact& contact)
{
	auto tagA = contact.getShapeA()->getBody()->getTag();
	auto tagB = contact.getShapeB()->getBody()->getTag();

	auto spriteA = contact.getShapeA()->getBody()->getNode();
	auto spriteB = contact.getShapeA()->getBody()->getNode();

	//子弹移除,匿名函数
	auto removeBullet = [&](Node* &bulletNode)
	{
		if (typeid(*bulletNode) == typeid(NuclearWeapon))
		{
			static_cast<NuclearWeapon*>(bulletNode)->explode();
		}
		else if (typeid(*bulletNode) == typeid(Bullet))
		{
			static_cast<Bullet*>(bulletNode)->explode();
		}
		else if (typeid(*bulletNode) == typeid(Bomb))
		{
			static_cast<Bomb*>(bulletNode)->explode();
		}
	};


	if (tagA == PLAYER_TAG || tagB == PLAYER_TAG)	//若碰撞中有玩家
	{
		if (tagA == PLAYER_TAG && tagB == ENEMY_TAG)
		{
			static_cast<PlayerTank*>(spriteA)->beAttacked(PLAYER_ENEMY_CONTACT);
		}
		else if (tagA == ENEMY_TAG &&tagB == PLAYER_TAG)
		{
			static_cast<PlayerTank*>(spriteB)->beAttacked(PLAYER_ENEMY_CONTACT);
		}
		else if (tagA == PLAYER_TAG && tagB == ENEMY_BULLET_TAG)
		{
			static_cast<PlayerTank*>(spriteA)->beAttacked(ENEMY_BULLET_DAMAGE);
			removeBullet(spriteB);
		}
		else if (tagA == ENEMY_BULLET_TAG && tagB == PLAYER_TAG)
		{
			static_cast<PlayerTank*>(spriteB)->beAttacked(ENEMY_BULLET_DAMAGE);
			removeBullet(spriteA);
		}
	}
	else if (tagA == ENEMY_TAG || tagB == ENEMY_TAG)//子弹和敌方碰撞
	{
		auto	enemyNode = spriteA;
		auto	bulletNode = spriteB;
		if (tagA == PLAYER_BULLET_TAG)
		{
			enemyNode = spriteB;
			bulletNode = spriteA;
		}
		auto enemy = static_cast<EnemyTank*>(enemyNode);
		int damage=PLAYER_BULLET_DAMAGE;
		if (typeid(*bulletNode) == typeid(Bomb))
			damage = BOMB_DAMAGE;
		else if (typeid(*bulletNode) == typeid(NuclearWeapon))
			damage = NUNLEAR_DAMAGE;

		enemy->beAttacked(damage);
		
		removeBullet(bulletNode);
	}
	else if (tagA == MAP_BARRIAR_TAG || tagB == MAP_BARRIAR_TAG)//子弹与不可跨越障碍物
	{
		auto	barrialNode = spriteA;
		auto	bulletNode = spriteB;
		if (tagA == ENEMY_BULLET_TAG || tagA == PLAYER_BULLET_TAG)
		{
			barrialNode = spriteB;
			bulletNode = spriteA;
		}

		if (typeid(*bulletNode) == typeid(Bomb) || typeid(*bulletNode) == typeid(NuclearWeapon))
		{
			barrialNode->removeFromParent();
		}

		removeBullet(bulletNode);
	}

	return true;
}