#ifndef __FTANK_H__
#define __FTANK_H__

#pragma  once

#include "cocos2d.h"
#include "../extensions/cocos-ext.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Bullet.h"

using namespace cocos2d::ui;

/*--------------------------------------------------------------
*NAME:	BloodBar
*DESC:	this is the Blood of tank
---------------------------------------------------------------*/
class BloodBar : public Node
{
public:
	static BloodBar* create();

	virtual bool init();

	//on blood recover
	void	increase(int blood);
	//on be attacked
	void	decreace(int blood);

	void	setRange(int maxBlood);
	void	setBlood(int blood);

	int		getBlood()const;

	cocos2d::Size	getBloodBarSize()const;		//获取血条的大小
protected:
	BloodBar();
	~BloodBar();

private:
	cocos2d::Sprite*			m_currBloodBar;	//当前血量同步精灵 作为这个控件的子节点
	cocos2d::Sprite*			m_bloodBg;		//血条背景

	int							m_range;		//血条范围
	int							m_currBlood;	//当前血量
};

/*---------------------------------------------------------------
*NAME:	FTank
*DESC:	this is the base of Tank.
---------------------------------------------------------------*/
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
	//init tank after created
	virtual bool init();

	//be attacked
	void		beAttacked(int damage);

protected:
	FTank();
	virtual ~FTank();

	//turning methods
	//turn diretion methods
	void	turnUp();
	void	turnDown();
	void	turnRight();
	void	turnLeft();

	//tank die and run a animation
	virtual void	goDie();
protected:
	BloodBar*					m_healthHub;			//blood

	Vec2						m_currentDir;			//current tank direction

	int							m_HP;					//blood level
	int							m_level;				//tank level
	int							m_damageLevel;			//value of attack

	cocos2d::Size				m_tankSize;				//size of tank
	float						m_angle;				//current angle after spin
	Vec2						m_headPoint;			//head to fire
	Vec2						m_healthBarPos;			//health bar position
};


/*-------------------------------------------------------------------------
*NAME:	EnemyTank
*DESC:	this kind of tank have it's own mind, sometimes it will kown how to 
*		avoid being attack and kown how to attack you
-------------------------------------------------------------------------*/
class EnemyTank :public FTank
{
public:
	//create function...
	CREATE_WITH_TEXTURE(EnemyTank);
	CREATE_WITH_FILE(EnemyTank);
	//init Tank after constructed
	virtual bool init();

	enum class EnemySpeed
	{
		ES_SPEED=45
	};
	//tank AI start! it should have it's own mind
	void		AIStart();

private:
	//fire method
	void	fire(float	dt);

	//update to change robot's reaction, in some way it looks like it has its own mind
	void	update(float dt);
private:
	Vec2			m_lastPostion;		//postion before update
protected:
	//let constructor and desconstructor be protected so that this class 
	//won't be created unconsitiously
	EnemyTank();
	virtual ~EnemyTank();

};

/*--------------------------------------------------------------------------
*NAME: PlayerTank
*DESC:
---------------------------------------------------------------------------*/
class PlayerTank :public FTank
{
public:
	//create function...
	CREATE_WITH_TEXTURE(PlayerTank);
	CREATE_WITH_FILE(PlayerTank);
	//attack type , in this way it will be convinient to extends
	enum class PlayerAction
	{
		PA_FIRE_BULLET,		//fire normal bullet
		PA_FIRE_BOMB,		//send big bombs
		PA_SLIDE,			//slide a little way
		PA_ULTIMATE,		//the ultimate skill
		PA_CALL_MERCENARY,	//call mercenries
		PA_TRANSFORM		//transform 
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
		PTS_LIGHT=35,
		PTS_HEAVY=25,
		PTS_LANDMINER=20
	};

	enum class PlayerTankMass		//mass of different type
	{
		PTM_LIGHT = 100,
		PTM_HEAVY = 300,
		PTM_LANDMINER=200
	};

	//init Tank after constructed
	virtual bool init();

	//controll by the player to move
	void		move(Ref *pSender, Widget::TouchEventType _touchType, FTank::TankDirect _dir);

	//try to attack
	void		act(Ref *pSender, Widget::TouchEventType _touchType, PlayerTank::PlayerAction _playerAction);

public:
	//DESC: refresh the CD time of skills
	//function type: return void, para: PlayerAction
	std::function<void(PlayerTank::PlayerAction _playerAction)>			onAct;				//cd time refresh 
	
	//
	std::function<void(Vec2  _dir)>										onMapMove;
protected:
	PlayerTank();
	virtual ~PlayerTank();

	//override goDie method
	virtual  void  goDie()override;
private:
	PlayerTankForm					m_currentForm;		//current form of player

	int								m_exp;				//exprence of the player
	int								m_skillCd[3];		//cd time of  3 skills
	int								m_transformCD;		//cd time of transform
};

#endif  //__FTANK_H__

