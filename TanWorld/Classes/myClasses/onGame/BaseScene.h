#ifndef _TEST_BASIC_H_
#define _TEST_BASIC_H_

#include "cocos2d.h"
#include "audio/include/SimpleAudioEngine.h"
#include "VisibleRect.h"

USING_NS_CC;

class BaseScene : public Scene
{
public:
	enum class VoiceLevel
	{
		VL_UP,
		VL_DOWN
	};

	//
	BaseScene(bool physics = false);
	virtual void onEnter() override;

	//background music 
	void		turnOnBgMusic(std::string _fileName);
	void		turnUpDown(VoiceLevel _vl);

	//pause
	void		gamePause();

	//
	void		returnToMainScene();

	//
	void		replaceThisScene();
	//compell every derived scene to override this method
	virtual void runThisScene() = 0;
};

// C++ 11

#define CL(__className__) [](){ return __className__::create();}
#define CLN(__className__) [](){ auto obj = new __className__(); obj->autorelease(); return obj; }

#endif