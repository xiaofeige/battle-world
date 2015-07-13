#ifndef _TEST_BASIC_H_
#define _TEST_BASIC_H_

#include "cocos2d.h"
#include "audio/include/SimpleAudioEngine.h"
#include "../extensions/cocos-ext.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "VisibleRect.h"

USING_NS_CC_EXT;
USING_NS_CC;
using namespace cocos2d::ui;
using namespace CocosDenshion;

class BaseScene : public Scene
{
public:
	enum class VoiceLevel
	{
		VL_UP,
		VL_DOWN
	};

	//
	BaseScene(bool physics = true);
	virtual void onEnter() override;

	//background music 
	void		turnOnBgMusic(Ref *pSender, Widget::TouchEventType _touchType);

	void		turnUpDown(Ref *pSender, Widget::TouchEventType _touchType,VoiceLevel _vl);

	//pause
	void		gamePause(Ref *pSender, Widget::TouchEventType _touchType);

	//
	void		returnToMainScene(Ref *pSender, Widget::TouchEventType _touchType);

	//
	void		replaceThisScene(Ref *pSender, Widget::TouchEventType _touchType);

	//compell every derived scene to override this method
	virtual void runThisScene() = 0;

private:
	bool				m_isBgMusicRunning;		//background music running status
};

// C++ 11

#define CL(__className__) [](){ return __className__::create();}
#define CLN(__className__) [](){ auto obj = new __className__(); obj->autorelease(); return obj; }

#endif