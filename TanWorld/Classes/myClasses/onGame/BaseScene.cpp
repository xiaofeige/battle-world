#include "BaseScene.h"
#include "extensions/cocos-ext.h"
#include "cocostudio/CocoStudio.h"

BaseScene::BaseScene(bool physics/* = false*/)
{
	BaseScene::initWithPhysics();	
}


void BaseScene::onEnter()
{
	Scene::onEnter();

	//set scene edge to limit the tank out of horizon
	auto visibleSize = VisibleRect::getVisibleRect().size;
	auto edge = Sprite::create();
	auto edgeBox = PhysicsBody::createEdgeBox(visibleSize, PHYSICSSHAPE_MATERIAL_DEFAULT, 1);
	edge->setPhysicsBody(edgeBox);
	edge->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	edge->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(edge);


	//add the menu item for back to main menu
	TTFConfig ttfConfig("fonts/arial.ttf", 20);
}

void BaseScene::runThisScene()
{
	auto	thisScene = BaseScene::create();

}

/*---------------------------------------------------------------------------------*/
/*------------------------------class name:BaseLayer--------------------------------*/
/*---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------*/

bool BaseLayer::init()
{
	if (!Layer::init())
		return false;

	//add your init code below...

	this->m_isBgMusicRunning = true;
	SimpleAudioEngine::getInstance()->playBackgroundMusic("music/loadingGame.wav", true);
	return true;
}

void BaseLayer::turnOnBgMusic(Ref *pSender, Widget::TouchEventType _touchType)
{
	if (_touchType == Widget::TouchEventType::ENDED)
	{
		if (this->m_isBgMusicRunning)	//if it is running then turn off
		{
			SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
			this->m_isBgMusicRunning = false;
		}
		else //turn on the music
		{
			this->m_isBgMusicRunning = true;
			SimpleAudioEngine::getInstance()->playBackgroundMusic("music/loadingGame.wav",true);
		}
	}
}

//pause
void BaseLayer::gamePause(Ref *pSender, Widget::TouchEventType _touchType)
{
	//
	Director::getInstance()->pause();
	SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

//
void BaseLayer::returnToMainScene(Ref *pSender, Widget::TouchEventType _touchType)
{

}

//
void BaseLayer::replaceThisScene(Ref *pSender, Widget::TouchEventType _touchType)
{

}