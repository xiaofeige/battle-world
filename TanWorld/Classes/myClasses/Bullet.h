#ifndef __Bullet_H__
#define __Bullet_H__

#include "cocos2d.h"
#include "BaseDefine.h"
#include "GameResource.h"
#include "VisibleRect.h"

USING_NS_CC;
/*------------------------------------------------------------------------------------
//definition of method to initial sprite with texture
-------------------------------------------------------------------------------------*/
#define CREATE_WITH_TEXTURE(__TYPE__) \
	static __TYPE__* createWithTexure(Texture2D* texture)\
{\
	__TYPE__* pRet = new (std::nothrow)__TYPE__(); \
if (pRet && pRet->initWithTexture(texture) && pRet->init())\
{\
	auto heroBody = PhysicsBody::createBox(pRet->getContentSize()); \
	heroBody->setDynamic(true); \
	heroBody->setContactTestBitmask(UNITIVE_MASK); \
	heroBody->setGravityEnable(false);  \
	pRet->setPhysicsBody(heroBody); \
	pRet->autorelease(); \
	return pRet; \
}\
else\
{\
	CC_SAFE_DELETE(pRet); \
	return nullptr; \
}\
}
/*------------------------------------------------------------------------------------
//definiton of method to init sprite with file
*-----------------------------------------------------------------------------------*/
#define CREATE_WITH_FILE(__TYPE__) \
	static __TYPE__* create(const std::string& fileName)\
{\
	__TYPE__* pRet = new (std::nothrow)__TYPE__(); \
if (pRet && pRet->initWithFile(fileName) && pRet->init())\
{\
	auto heroBody = PhysicsBody::createBox(pRet->getContentSize()); \
	heroBody->setDynamic(true); \
	heroBody->setRotationEnable(false); \
	heroBody->setContactTestBitmask(UNITIVE_MASK); \
	heroBody->setGravityEnable(false);  \
	pRet->setPhysicsBody(heroBody); \
	pRet->autorelease(); \
	return pRet; \
}\
else\
{\
	CC_SAFE_DELETE(pRet); \
	return nullptr; \
}\
}


/*--------------------------------------------------------------------------------------
*NAME:	Bullet
*DESC:	this is the class of Bullet.
*-------------------------------------------------------------------------------------*/
class Bullet : public Sprite
{
public:
	CREATE_WITH_FILE(Bullet);
	CREATE_WITH_TEXTURE(Bullet);

	virtual bool	init();
	virtual void	explode();
	int				getDamageRange()const;
protected:
	Bullet();
	virtual ~Bullet();

	int				m_dagameRange;		//…±…À∑∂Œß
	int				m_damage;			//…À∫¶
};


/*----------------------------------------------------------------------------------------
*NAME:	Bomb
*DESC:	this is the class of Bomb.
----------------------------------------------------------------------------------------*/
class Bomb :public Bullet
{
public:
	//
	virtual void	explode()override;
	virtual bool	init();

	CREATE_WITH_FILE(Bomb);
	CREATE_WITH_TEXTURE(Bomb);

protected:
	Bomb();
	~Bomb();

private:
	void			removeStunt(float dt);
	ParticleSystemQuad*			m_bom;
};


/*----------------------------------------------------------------------------------------
*NAME:	NuclearWeapon
*DESC:	this is the class of NuclearWeapon which is the most powerful skill of player
-----------------------------------------------------------------------------------------*/
class NuclearWeapon :public Bullet
{
public:
	virtual void	explode()override;
	virtual bool	init();

	CREATE_WITH_FILE(NuclearWeapon);
	CREATE_WITH_TEXTURE(NuclearWeapon);

protected:
	NuclearWeapon();
	~NuclearWeapon();
};

#endif   //__BULLET_H__