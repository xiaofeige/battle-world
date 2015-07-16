#include "chapter1.h"




bool Chapter1::init()
{
	if (!BaseLayer::init())
		return false;

	//add your init code below...


	return true;
}

bool Chapter1::contactListen(const PhysicsContact& contact)
{
	auto spriteA = contact.getShapeA()->getBody()->getTag();
	auto spriteB = contact.getShapeB()->getBody()->getTag();
}