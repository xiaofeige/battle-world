#include "BaseScene.h"
#include "extensions/cocos-ext.h"
#include "cocostudio/CocoStudio.h"

BaseScene::BaseScene(bool physics/* = false*/)
:m_isBgMusicRunning(false)
{
	BaseScene::initWithPhysics();
}


void BaseScene::onEnter()
{
	Scene::onEnter();

	//add the menu item for back to main menu
	TTFConfig ttfConfig("fonts/arial.ttf", 20);
	
	this->m_isBgMusicRunning = true;
	SimpleAudioEngine::getInstance()->playBackgroundMusic("music/loadingGame.wav", true);
}

void BaseScene::turnOnBgMusic(Ref *pSender, Widget::TouchEventType _touchType)
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

void BaseScene::turnUpDown(Ref *pSender, Widget::TouchEventType _touchType, VoiceLevel _vl)
{

}

//pause
void BaseScene::gamePause(Ref *pSender, Widget::TouchEventType _touchType)
{

}

//
void BaseScene::returnToMainScene(Ref *pSender, Widget::TouchEventType _touchType)
{

}

//
void BaseScene::replaceThisScene(Ref *pSender, Widget::TouchEventType _touchType)
{

}