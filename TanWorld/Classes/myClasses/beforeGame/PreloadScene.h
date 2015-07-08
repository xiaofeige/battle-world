#ifndef __PRELOADSCENE_SCENE_H__
#define __PRELOADSCENE_SCENE_H__

#include "cocos2d.h"

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