#ifndef __PRELOADSCENE_SCENE_H__
#define __PRELOADSCENE_SCENE_H__

#include "cocos2d.h"
/*-----------------------------------------------------------------------------------
*CLASS NAME:  £Ð£ò£å£ì£ï£á£ä£Ó£ã£å£î£å
*DESC:	when this app is started,this scene be loaded to show the company logo ,in
		the same time,pictures and musics etc. should be loaded into memory.
------------------------------------------------------------------------------------*/
class PreloadScene : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	//jump to main page of the game
	void	jumpOut(float dt);

	//preload files
	void	preloadFiles();
	// implement the "static create()" method manually
	CREATE_FUNC(PreloadScene);
};

#endif // __PRELOADSCENE_SCENE_H__