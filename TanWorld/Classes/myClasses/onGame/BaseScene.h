#ifndef _BASE_LAYER_H_
#define _BASE_LAYER_H_

#include "audio/include/SimpleAudioEngine.h"
#include "../extensions/cocos-ext.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "VisibleRect.h"
#include "../Bullet.h"

#include "BaseDefine.h"
#include "AISystem.h"

//USING_NS_CC_EXT;
//USING_NS_CC;
using namespace cocos2d::ui;
using namespace CocosDenshion;


#define RUN_THIS_CHAPTER(__TYPE__) \
	virtual void runThisChapter() \
{ \
	auto scene = Scene::createWithPhysics(); \
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL); \
	auto gameLayer = __TYPE__::create(); \
	scene->addChild(gameLayer); \
	auto transScene = TransitionTurnOffTiles::create(0.8f, scene); \
	Director::getInstance()->replaceScene(transScene); \
}


class BaseLayer :public cocos2d::Layer
{
public:
	BaseLayer();
	~BaseLayer();
	virtual bool init();
	virtual void runThisChapter()=0;

	//background music
	void		turnOnBgMusic(Ref *pSender, Widget::TouchEventType _touchType);

	//pause
	void		gamePause(Ref *pSender, Widget::TouchEventType _touchType);

	//
	void		returnToMainScene(Ref *pSender, Widget::TouchEventType _touchType);

protected:
	//Åö×²¼ì²â
	bool		contactListen(const PhysicsContact& contact);


	bool							m_isBgMusicRunning;		//background music running status

	PlayerTank*						m_currentPlayer;

	AISystem						m_AIManager;			//AI system	manager
};
// C++ 11
#endif		//__BASE_LAYER_H__