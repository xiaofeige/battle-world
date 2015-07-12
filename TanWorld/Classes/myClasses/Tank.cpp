#include "Tank.h"

//====================================================================
//=============class name:FTank
//====================================================================
//2015-7-12
FTank::FTank()
{

}


//====================================================================
//=============class name:EnemyTank
//====================================================================
//2015-7-12
EnemyTank* EnemyTank::createWithTexture(Texture2D *texture)
{
	EnemyTank* enemyTank = new (std::nothrow) EnemyTank();
	if (enemyTank && enemyTank->initWithTexture(texture))
	{
		enemyTank->autorelease();
		return enemyTank;
	}
	CC_SAFE_DELETE(enemyTank);
	return nullptr;
}


//====================================================================
//=============class name:PlayerTank
//====================================================================
//2015-7-12
void PlayerTank::move(Ref *pSender, Widget::TouchEventType _touchType, FTank::TankDirect _dir)
{
	if (_touchType == Widget::TouchEventType::MOVED)
	{
		switch (_dir)
		{
		case FTank::TankDirect::TD_UP:
		{
										 break;
		}
			
		case FTank::TankDirect::TD_UP_RIGHT:
		{
											   break;
		}
			
		case FTank::TankDirect::TD_RIGHT:
		{
											break;
		}
		case FTank::TankDirect::TD_RIGHT_DOWN:
		{
												 break;
		}
		case FTank::TankDirect::TD_DOWN:
		{
										   break;
		}
		case FTank::TankDirect::TD_DOWN_LEFT:
		{
												break;
		}
		case FTank::TankDirect::TD_LEFT:
		{
										   break;
		}
		case FTank::TankDirect::TD_LEFT_UP:
		{
											  break;
		}
		default:
			break;
		}
	}
	//if button released, set velocity equals zero
	else if (_touchType == Widget::TouchEventType::ENDED)
	{

	}
}
