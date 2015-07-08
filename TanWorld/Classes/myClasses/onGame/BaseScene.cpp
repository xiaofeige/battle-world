#include "BaseScene.h"
#include "extensions/cocos-ext.h"
#include "cocostudio/CocoStudio.h"

BaseScene::BaseScene(bool physics/* = false*/)
{
	if (physics)
	{
#if CC_USE_PHYSICS
		BaseScene::initWithPhysics();
#else
		Scene::init();
#endif
	}
	else
	{
		Scene::init();
	}
}


void BaseScene::onEnter()
{
	Scene::onEnter();

	//add the menu item for back to main menu
	TTFConfig ttfConfig("fonts/arial.ttf", 20);
	

}