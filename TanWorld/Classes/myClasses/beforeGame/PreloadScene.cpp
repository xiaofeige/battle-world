#include "PreloadScene.h"
#include "MainMenu.h"
#include<thread>
#include "VisibleRect.h"

USING_NS_CC;

Scene* PreloadScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = PreloadScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool PreloadScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	//3 seconds to show our logo
	scheduleOnce(CC_SCHEDULE_SELECTOR(PreloadScene::jumpOut), 3.0f);  

	//init our logo here...
	auto logo = Sprite::create("FHtankLogo.png");
	auto _visibleRect = VisibleRect::getVisibleRect();
	logo->setPosition(Vec2(_visibleRect.size.width / 2, _visibleRect.size.height / 2));
	this->addChild(logo);

	//try to load files the game need
	std::thread  preloadThread(&PreloadScene::preloadFiles, this);
	preloadThread.detach();

	return true;
}

/*
*NAME:jumpOut
*PARA:float dt refers to during time
*DESC:by TransitionTurnOffTiles jump, during time is 0.8 seconds;
**/
void PreloadScene::jumpOut(float dt)
{
	auto mainMenuScene = MainMenu::createScene();
	auto transScene = TransitionTurnOffTiles::create(0.8f, mainMenuScene);
	auto director = Director::getInstance();

	director->replaceScene(transScene);
}

/*
*NAME:preloadFiles
*PARA:N
*DESC:preload pictures,musics,and so on...
**/
void PreloadScene::preloadFiles()
{
	
}