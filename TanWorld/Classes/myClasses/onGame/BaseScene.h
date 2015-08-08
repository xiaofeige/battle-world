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
-------------------------------------------------------------------------------------*/
class BaseLayer :public cocos2d::Layer
{
public:
	BaseLayer();
	~BaseLayer();

	//init this layer when created 
	virtual bool init();
	//every chapter should have this method to create a scene to load this layer
	virtual void runThisChapter()=0;

	//background music
	void		turnOnBgMusic(Ref *pSender, Widget::TouchEventType _touchType);

	//pause
	void		gamePause(Ref *pSender, Widget::TouchEventType _touchType);

	//return to main menu
	void		returnToMainScene(Ref *pSender, Widget::TouchEventType _touchType);

	//refresh CD time to controll the button
	void		refreshButtonCD(float dt);

	//controll the map to move
	void		onMapMove(Vec2 _dir);

protected:
	//method of contact test
	bool		contactListen(const PhysicsContact& contact);

protected:
	cocos2d::Node*					m_map;					//µØÍ¼

	bool							m_isBgMusicRunning;		//background music running status
	PlayerTank*						m_currentPlayer;
	AISystem						m_AIManager;			//AI system	manager

	int								m_chapterNo;			//¹Ø¿¨ºÅ
};
// C++ 11
#endif		//__BASE_LAYER_H__