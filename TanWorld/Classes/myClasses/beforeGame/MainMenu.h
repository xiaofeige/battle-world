#ifndef __MAINMENU_SCENE_H__
#define __MAINMENU_SCENE_H__

#include "cocos2d.h"
#include "..\GameHandleLib.h"

class MainMenu : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	//menu of game
	void menuStart(cocos2d::Ref* pSender);

	//player feedback
	void menuFeedback(cocos2d::Ref* pSender);

	//exit game
	void menuCloseCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(MainMenu);
};

#endif // __MAINMENU_SCENE_H__