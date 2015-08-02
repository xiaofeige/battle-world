
#include "Bullet.h"

//====================================================================
//=============class name:Bullet
//====================================================================
//2015-7-23
Bullet::Bullet()
{

}
Bullet::~Bullet()
{

}

bool Bullet::init()
{

	return true;
}

void Bullet::explode()
{

}

int Bullet::getDamageRange()const
{
	return m_dagameRange;
}

//====================================================================
//=============class name:Bomb
//====================================================================
//2015-7-23
Bomb::Bomb()
{

}
Bomb::~Bomb()
{
	
}

bool Bomb::init()
{
	//super init first~
	if (!Bullet::init())
		return false;


	return true;
}

void Bomb::explode()
{

}

//====================================================================
//=============class name:NuclearWeapon
//====================================================================
//2015-7-23

NuclearWeapon::NuclearWeapon()
{

}

NuclearWeapon::~NuclearWeapon()
{

}

bool NuclearWeapon::init()
{
	//super init first~
	if (!Bullet::init())
		return false;


	return true;
}

void NuclearWeapon::explode()
{

}

