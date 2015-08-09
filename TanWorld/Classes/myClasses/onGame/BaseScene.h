#ifndef _BASE_LAYER_H_
#define _BASE_LAYER_H_

#include "audio/include/SimpleAudioEngine.h"
#include "../extensions/cocos-ext.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "AISystem.h"

using namespace cocos2d::ui;
using namespace CocosDenshion;

//definition of unitive method to run this chapter
#define RUN_THIS_CHAPTER(__TYPE__) \
	virtual void runThisChapter() \
{ \
	auto scene = Scene::createWithPhysics(); \
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL); \
	scene->addChild(this); \
	auto transScene = TransitionTurnOffTiles::create(0.8f, scene); \
	Director::getInstance()->replaceScene(transScene); \
}

/*------------------------------------------------------------------------------------
*CLASS NAME: BaseLayer
*DESC: common abilities of each chapter,including music controll and contact test
*USAGE: to inherit this class and implement the "runThisChapter" method.
		watch out: only when you have load the map first can you init a player in a map
		or no player will show up
-------------------------------------------------------------------------------------*/
class BaseLayer :public cocos2d::Layer
{
public:
	BaseLayer();
	~BaseLayer();

	//init this layer when created
	//DESC: including creating a edge to limit tank
	virtual bool init();
	//every chapter should have this method to create a scene to load this layer
	virtual void runThisChapter()=0;

	//trun on the background music ,this will called when scene is initialized first
	void		turnOnBgMusic(Ref *pSender, Widget::TouchEventType _touchType);

	//pause the game
	void		gamePause(Ref *pSender, Widget::TouchEventType _touchType);

	//return to main menu
	void		returnToMainScene(Ref *pSender, Widget::TouchEventType _touchType);

	//refresh CD time to controll the button
	void		refreshButtonCD(float dt);

	//controll the map to move
	void		onMapMove(Vec2 _dir);

protected:
	//init playar in scene
	//DESC: set player in the scene and set button event bind with tank action methods
	//		this will call the next function--> setButtonListener.
	//		in this way to ensure it is safe to add player to the scene and set event 
	//		listener
	void		initPlayer();

	//set button listener
	//DESC: as is described above , this method will called when player initialized
	void		setButtonListener();

	//set contact listener
	//DESC: called when baseScene initialized
	void		setContactListener();
	//method of contact test
	//DESC: controll what to do when a Collision is heard
	bool		contactListen(const PhysicsContact& contact);

protected:
	cocos2d::Node*					m_map;					//地图

	bool							m_isBgMusicRunning;		//background music running status
	PlayerTank*						m_currentPlayer;
	AISystem						m_AIManager;			//AI system	manager

	int								m_chapterNo;			//关卡号

	ui::Button*						m_skillButton[4];		//技能键
};
// C++ 11
#endif		//__BASE_LAYER_H__
