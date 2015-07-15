#ifndef __FTANK_H__
#define __FTANK_H__

#pragma  once

#include "cocos2d.h"
#include "../extensions/cocos-ext.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC_EXT;
USING_NS_CC;
using namespace cocos2d::ui;


/*
*NAME:	FTank
*DESC:	this is the base of Tank.
*/
class FTank : public Sprite
{
public:
	//tank direction definition;
	enum class TankDirect
	{
		TD_UP,
		TD_UP_RIGHT,
		TD_RIGHT,
		TD_RIGHT_DOWN,
		TD_DOWN,
		TD_DOWN_LEFT,
		TD_LEFT,
		TD_LEFT_UP
	};

	//be attacked
	void		beAttacked(int damage);

private:
	FTank();
	~FTank();


	TankDirect					m_currentDir;			//current tank direction

	int							m_HP;					//blood level
	int							m_level;				//tank level
	int							m_damageLevel;			//value of attack
};


/*
*NAME:	EnemyTank
*DESC:	this kind of tank have it's own mind, sometimes it will kown how to 
*		avoid being attack and kown how to attack you
*/
class EnemyTank :public FTank
{
public:
	//create function...
	static EnemyTank*	create(std::string& fileName);
	static EnemyTank*	createWithTexture(Texture2D *texture);


	//tank AI start! it should have it's own mind
	void		AIStart();

private:
	//let constructor and desconstructor be private so that this class 
	//won't be created unconsitiously
	EnemyTank();
	~EnemyTank();

};

/*
*NAME: PlayerTank
*DESC: 
*/
class PlayerTank :public FTank
{
public:
	//create function...
	static PlayerTank*		create(std::string& fileName);
	static PlayerTank*		createWithTexture(Texture2D *texture);

	//attack type , in this way it will be convinient to extends
	enum class PlayerAction
	{
		PA_FIRE_BULLET,		//fire normal bullet
		PA_FIRE_BOMB,		//send big bombs
		PA_SLIDE,			//slide a little way
		PA_ULTIMATE,		//the ultimate skill
		PA_CALL_MERCENARY	//call mercenries
	};

	//playerTank type, it has diffent type with diffent abbility
	enum class PlayerTankForm
	{
		PTF_HEAVY,		//heavy tank which can launch heavy artillery
		PTF_LIGHT,		//light tank which is faster
		PTF_LANDMINER	//miner tank which can install landmines
	};

	enum class PlayerTankSpeed		//the value need to be considered later+++++
	{
		PTS_LIGHT=25,
		PTS_HEAVY=15,
		PTS_LANDMINER=10
	};
	//controll by the player to move
	void		move(Ref *pSender, Widget::TouchEventType _touchType, FTank::TankDirect _dir);

	//try to attack
	void		act(Ref *pSender, Widget::TouchEventType _touchType, PlayerTank::PlayerAction _playerAction);
private:
	PlayerTank();
	~PlayerTank();

	PlayerTankForm					m_currentForm;		//current form of player

	int								m_exp;				//exprence of the player
	int								m_skillCd[3];		//cd time of  3 skills
	int								m_transformCD;		//cd time of transform 
};

#endif  //__FTANK_H__

