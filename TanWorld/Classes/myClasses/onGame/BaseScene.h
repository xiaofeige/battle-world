#ifndef _TEST_BASIC_H_
#define _TEST_BASIC_H_

#include "cocos2d.h"
#include "audio/include/SimpleAudioEngine.h"
#include "../extensions/cocos-ext.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "VisibleRect.h"
#include "..\Tank.h"

USING_NS_CC_EXT;
USING_NS_CC;
using namespace cocos2d::ui;
using namespace CocosDenshion;


#define RUN_THIS_CHAPTER(__TYPE__) \
	void runThisChapter() \
{ \
	auto scene = Scene::createWithPhysics(); \
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_NONE); \
	auto gameLayer = __TYPE__::create(); \
	scene->addChild(gameLayer); \
	auto transScene = TransitionTurnOffTiles::create(0.8f, scene); \
	Director::getInstance()->replaceScene(transScene); \
}


class BaseLayer :public cocos2d::Layer
{
public:
	virtual bool init();
	CREATE_FUNC(BaseLayer);

	//background music
	void		turnOnBgMusic(Ref *pSender, Widget::TouchEventType _touchType);

	//pause
	void		gamePause(Ref *pSender, Widget::TouchEventType _touchType);

	//
	void		returnToMainScene(Ref *pSender, Widget::TouchEventType _touchType);


	//当玩家到达指定位置 则发生将滚动一次地面
	void		moveBackground();


private:
	bool							m_isBgMusicRunning;		//background music running status

	PlayerTank*						m_currentPlayer;
	std::condition_variable			m_shouldMove;
};
// C++ 11

#define CL(__className__) [](){ return __className__::create();}
#define CLN(__className__) [](){ auto obj = new __className__(); obj->autorelease(); return obj; }

#endif