
#include "Bullet.h"

//====================================================================
//=============class name:Bullet
//====================================================================
//2015-7-23
Bullet::Bullet()
:m_damage(PLAYER_BULLET_DAMAGE)
, m_dagameRange(BULLET_DAMAGE_RANGE)
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
	this->removeFromParentAndCleanup(true);
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
	m_damage = BOMB_DAMAGE_RANGE;
	m_dagameRange = BOMB_DAMAGE_RANGE;
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
	this->getPhysicsBody()->removeFromWorld();

	auto CurrentPoint = this->getPosition();
	auto body = PhysicsBody::createCircle(m_dagameRange, PHYSICSSHAPE_MATERIAL_DEFAULT, Vec2::ZERO);	
	this->setPhysicsBody(body);
	
	m_bom = ParticleSystemQuad::create("explode/BOM.plist");
	addChild(m_bom);
	m_bom->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	m_bom->setPosition(Vec2(0,0));

		
	scheduleOnce(CC_SCHEDULE_SELECTOR(Bomb::removeStunt), 0.5f);
}
void Bomb::removeStunt(float dt)
{
	this->removeFromParentAndCleanup(true);
}
//====================================================================
//=============class name:NuclearWeapon
//====================================================================
//2015-7-23

NuclearWeapon::NuclearWeapon()
{
	m_damage = NUCLEAR_WEAPON_DAMAGE;
	m_dagameRange = NUCLEAR_WEAPON_DAMAGE_RANGE;
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

