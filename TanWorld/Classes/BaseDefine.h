////////////////////////////////////////////////////////////////////////////////////////
//
//								basic defenition of game
//
////////////////////////////////////////////////////////////////////////////////////////

//物理对象标签
#define		PLAYER_TAG				1001	//玩家标签
#define		ENEMY_TAG				1002	//敌方标签
#define		MAP_BARRIAR_TAG			1003	//地图障碍物标签
#define		PLAYER_BULLET_TAG		1004	//玩家子弹标签
#define		ENEMY_BULLET_TAG		1005	//敌方


//物理对象掩码
#define		UNITIVE_MASK			0x0001	//通用碰撞掩码
#define		RIVER_MASK				0x0002	//河流碰撞掩码

//子弹伤害
#define		PLAYER_ENEMY_CONTACT	40		//玩家和敌方碰撞的伤害
#define		ENEMY_BULLET_DAMAGE		20		//地方子弹伤害
#define		PLAYER_BULLET_DAMAGE	20		//普通子弹伤害
#define		BOMB_DAMAGE				40		//炮弹伤害
#define		LASER_DAMAGE			80		//激光伤害
#define		NUNLEAR_DAMAGE			80		//核弹伤害


#define		PLAYER_NAME				"player"//玩家名
//文件路径
