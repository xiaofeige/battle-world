#include "Tank.h"

//====================================================================
//=============class name:BloodBar
//====================================================================
//2015-7-12

BloodBar::BloodBar()
:m_currBloodBar(nullptr)
, m_bloodBg(nullptr)
{

}
BloodBar::~BloodBar()
{

}
BloodBar* BloodBar::create()
{
	BloodBar* pBloodBar = new (std::nothrow)BloodBar();
	if (pBloodBar && pBloodBar->init())
	{
		pBloodBar->autorelease();
		return pBloodBar;
	}
	else
	{
		CC_SAFE_DELETE(pBloodBar);
		return nullptr;
	}
}
//BloodBar* BloodBar::create(const std::string& fileName)
//{
//	BloodBar* pBloodBar = new (std::nothrow)BloodBar();
//	if (pBloodBar && pBloodBar->initWithFile(fileName) && pBloodBar->init())
//	{
//		pBloodBar->autorelease();
//		return pBloodBar;
//	}
//	else
//	{
//		CC_SAFE_DELETE(pBloodBar);
//		return nullptr;
//	}
//}
//
//BloodBar* BloodBar::createWithTexure(Texture2D* bgRange)
//{
//	BloodBar* pBloodBar = new (std::nothrow)BloodBar();
//	if (pBloodBar && pBloodBar->initWithTexture(bgRange) && pBloodBar->init())
//	{
//		pBloodBar->autorelease();
//		return pBloodBar;
//	}
//	else
//	{
//		CC_SAFE_DELETE(pBloodBar);
//		return nullptr;
//	}
//}

bool BloodBar::init()
{
	m_bloodBg = Sprite::create(hubBgPath);
	m_bloodBg->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	m_currBloodBar = Sprite::create(hubPath);
	m_currBloodBar->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	m_bloodBg->addChild(m_currBloodBar);

	m_currBloodBar->setPosition(Vec2(0,0));

	m_bloodBg->setPosition(Vec2(0,0));

	this->addChild(m_bloodBg);

	return true;
}
void BloodBar::increase(int blood)
{
	m_currBlood += blood;
	float rate = m_currBlood / m_range;
	float currWidth = this->getContentSize().height / m_currBloodBar->getContentSize().height;
	m_currBloodBar->setScaleX(rate*currWidth);
}
void BloodBar::decreace(int blood)
{
	m_currBlood -= blood;
	float rate = m_currBlood / m_range;
	float currWidth = this->getContentSize().height / m_currBloodBar->getContentSize().height;
	m_currBloodBar->setScaleX(rate*currWidth);
}

void BloodBar::setRange(int maxBlood)
{
	m_range = maxBlood;
}
void BloodBar::setBlood(int blood)
{
	m_currBlood = blood;
}

int BloodBar::getBlood()const
{
	return m_currBlood;
}
Size BloodBar::getBloodBarSize()const
{
	return m_bloodBg->getContentSize();
}
//====================================================================
//=============class name:FTank
//====================================================================
//2015-7-12
FTank::FTank()
:m_angle(0.0f)
, m_currentDir(Vec2(0,1))
{

}
FTank::~FTank()
{

}

bool FTank::init()
{
	//add your code below...

	


	return true;
}

void FTank::beAttacked(int damage)
{
	m_HP -= damage;
	m_healthHub->decreace(damage);
}


//====================================================================
//=============class name:EnemyTank
//====================================================================
//2015-7-12
EnemyTank::EnemyTank()
{

}

EnemyTank::~EnemyTank()
{

}

bool EnemyTank::init()
{
	//super init first...
	if (!FTank::init())
		return false;
	//add your code below
	//get tank size +++++++++++


	return true;
}

void EnemyTank::AIStart()
{

}
//====================================================================
//=============class name:PlayerTank
//====================================================================
//2015-7-12

PlayerTank::PlayerTank()
:m_currentForm(PlayerTank::PlayerTankForm::PTF_LIGHT)
{
	
}
PlayerTank::~PlayerTank()
{

}
bool PlayerTank::init()
{
	//add your code below...
	if (!FTank::init())
		return false;

	//////////////////////////
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	//add blood bar
	m_healthHub = BloodBar::create();
	m_healthHub->setAnchorPoint(Vec2::ANCHOR_MIDDLE);

	m_tankSize = this->getContentSize();

	m_healthHub->setPosition(Vec2(m_tankSize.width/2,m_tankSize.height+10));
	m_headPoint = Vec2(m_tankSize.width / 2, m_tankSize.height + 10);

	m_healthHub->setScale(0.05f);

	this->addChild(m_healthHub);

	return true;
}

void PlayerTank::move(Ref *pSender, Widget::TouchEventType _touchType, FTank::TankDirect _dir)
{
	if (_touchType == Widget::TouchEventType::MOVED || _touchType == Widget::TouchEventType::BEGAN)
	{
		//get speed based on tank form
		int speed;
		if (m_currentForm == PlayerTank::PlayerTankForm::PTF_HEAVY)
			speed = (int)(PlayerTank::PlayerTankSpeed::PTS_HEAVY);
		else if (m_currentForm == PlayerTank::PlayerTankForm::PTF_LIGHT)
			speed = (int)(PlayerTank::PlayerTankSpeed::PTS_LIGHT);
		else
			speed = (int)(PlayerTank::PlayerTankSpeed::PTS_LANDMINER);


		switch (_dir)
		{
		case FTank::TankDirect::TD_UP:
		{
										 this->m_currentDir = Vec2(0,1);
										 this->setRotation(0.0f);
										 m_angle = 0.0f;
										 m_headPoint = Vec2(m_tankSize.width/2,m_tankSize.height);

										 this->getPhysicsBody()->setVelocity(Vec2(0, 0 + speed));
										 break;
		}

		case FTank::TankDirect::TD_UP_RIGHT:
		{
											   this->m_currentDir = Vec2(0.5,0.5);
											   this->setRotation(45.0f);
											   m_angle = 45.0f;
											   m_headPoint = Vec2();

											   this->getPhysicsBody()->setVelocity(Vec2(0 + cos(speed), 0 + sin(speed)));
											   break;
		}

		case FTank::TankDirect::TD_RIGHT:
		{
											this->m_currentDir = Vec2(1,0);
											this->setRotation(90.0f);
											m_angle = 90.0f;
											m_headPoint = Vec2(m_tankSize.height, m_tankSize.width / 2);

											this->getPhysicsBody()->setVelocity(Vec2(0 + speed, 0));
											break;
		}
		case FTank::TankDirect::TD_RIGHT_DOWN:
		{
												 this->m_currentDir = Vec2(0.5,-0.5);
												 this->setRotation(135.0f);
												 m_angle = 135.0f;

												 this->getPhysicsBody()->setVelocity(Vec2(0 + cos(speed), 0 - sin(speed)));
												 break;
		}
		case FTank::TankDirect::TD_DOWN:
		{
										   this->m_currentDir = Vec2(0,-1);
										   this->setRotation(180.0f);
										   m_angle = 180.0f;
										   m_headPoint = Vec2(m_tankSize.width / 2, 0);

										   this->getPhysicsBody()->setVelocity(Vec2(0, 0 - speed));
										   break;
		}
		case FTank::TankDirect::TD_DOWN_LEFT:
		{
												this->m_currentDir = Vec2(-0.5,-0.5);
												this->setRotation(225.0f);
												m_angle = 225.0f;

												this->getPhysicsBody()->setVelocity(Vec2(0 - cos(speed), 0 - sin(speed)));
												break;
		}
		case FTank::TankDirect::TD_LEFT:
		{
										   this->m_currentDir = Vec2(-1,0);
										   this->setRotation(270.0f);
										   m_angle = 270.0f;
										   m_headPoint = Vec2(0, m_tankSize.width/2);

										   this->getPhysicsBody()->setVelocity(Vec2(0 - speed, 0));
										   break;
		}
		case FTank::TankDirect::TD_LEFT_UP:
		{
											  this->m_currentDir = Vec2(-0.5,0.5);
											  this->setRotation(315.0f);
											  m_angle = 315.0f;
											  m_headPoint = Vec2(m_tankSize.width / 2, m_tankSize.height);

											  this->getPhysicsBody()->setVelocity(Vec2(0 - cos(speed), 0 + sin(speed)));
											  break;
		}
		default:
			break;
		}

		m_healthHub->setRotation(360.0f-m_angle);
		m_healthHub->setPosition(Vec2(m_tankSize.width / 2, m_tankSize.height + 10));
	}
	//if button released, set velocity equals zero
	else if (_touchType == Widget::TouchEventType::ENDED)
	{
		this->getPhysicsBody()->setVelocity(Vec2::ZERO);
	}

}

void PlayerTank::act(Ref *pSender, Widget::TouchEventType _touchType, PlayerTank::PlayerAction _playerAction)
{
	if (_touchType == Widget::TouchEventType::BEGAN)
	{
		if (m_currentForm == PlayerTank::PlayerTankForm::PTF_LIGHT)
		{
			switch (_playerAction)
			{
			case PlayerTank::PlayerAction::PA_FIRE_BULLET:
			{
															 auto bullet = Bullet::create("pic/bullet.png");
															 this->getParent()->addChild(bullet);
															 bullet->setPosition(this->getPosition() + m_headPoint);
															 bullet->setRotation(m_angle);

															 bullet->getPhysicsBody()->setVelocity(Vec2(m_currentDir.x*55,m_currentDir.y*55));
															 break;
			}

			case PlayerTank::PlayerAction::PA_FIRE_BOMB:
			{
														   auto bomb = Bomb::create("pic/bomb.png");
														   this->getParent()->addChild(bomb);
														   bomb->setPosition(this->getPosition() + m_headPoint);
														   bomb->setRotation(m_angle);

														   bomb->getPhysicsBody()->setVelocity(Vec2(m_currentDir.x * 35, m_currentDir.y * 35));
														   break;
			}
			case PlayerTank::PlayerAction::PA_SLIDE:
			{
													   break;
			}
			case PlayerTank::PlayerAction::PA_CALL_MERCENARY:
			{
																break;
			}
			case PlayerTank::PlayerAction::PA_ULTIMATE:
			{
														  break;
			}
			}

		}
	}
}