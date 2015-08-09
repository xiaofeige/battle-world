#include "MainMenu.h"
#include "../onGame/SelectView.h"
#include "VisibleRect.h"

USING_NS_CC;

Scene* MainMenu::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MainMenu::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	//add background image
	auto tankBattleImg = Sprite::create(preloadingImgPath);
	tankBattleImg->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	tankBattleImg->setPosition(VisibleRect::center());
	this->addChild(tankBattleImg);

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(MainMenu::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	// create menu, it's an autorelease object
	auto menuClose = Menu::create(closeItem, NULL);
	menuClose->setPosition(Vec2::ZERO);
	this->addChild(menuClose, 1);

	//create user select menu...
	MenuItemFont::setFontName("fonts/Marker Felt.ttf");
	auto itemStart = MenuItemFont::create("let get it started!", CC_CALLBACK_1(MainMenu::menuStart, this));
	auto itemFeedBack = MenuItemFont::create("contact us!", CC_CALLBACK_1(MainMenu::menuFeedback, this));
	auto menu = Menu::create(itemStart, itemFeedBack, nullptr);
	menu->alignItemsHorizontallyWithPadding(200.0f);
	auto menuPos = VisibleRect::center();
	menu->setPosition(Vec2(menuPos.x,menuPos.y/2));
	this->addChild(menu);
	
	return true;
}
void MainMenu::menuStart(cocos2d::Ref* pSender)
{
	auto gateSelectView = SelectView::create();
	this->addChild(gateSelectView);

	gateSelectView->getTableView()->setPosition(VisibleRect::center());
}

void MainMenu::menuFeedback(cocos2d::Ref* pSender)
{
	Application::getInstance()->openURL("http://flewawayblog.sinaapp.com/");
}

void MainMenu::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
	return;
#endif

	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}