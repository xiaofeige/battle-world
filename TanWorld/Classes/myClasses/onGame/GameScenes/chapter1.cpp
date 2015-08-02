#include "chapter1.h"




bool Chapter1::init()
{
	if (!BaseLayer::init())
		return false;

	//add your init code below...
	
	//first set the player position in the map
	m_currentPlayer->setPosition(VisibleRect::center());


	return true;
}

