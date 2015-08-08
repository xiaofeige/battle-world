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
#define		EDGE_BOX_TAG			1006	//外围墙标签
#define		MAP_POOL_TAG			1007	//地图中湖泊标签


//物理对象掩码
#define		UNITIVE_MASK			0xffffffff	//通用碰撞掩码
#define		POOL_MASK				0x00000000	//河流碰撞掩码

//物理对象种群
#define		WEAPON_GROUP			1			//武器种群
#define		PLAYER_GROUP			2			//玩家种群
#define		ENEMY_GROUP				2

//子弹伤害
#define		PLAYER_ENEMY_CONTACT	40		//玩家和敌方碰撞的伤害
#define		ENEMY_BULLET_DAMAGE		20		//敌方子弹伤害
#define		PLAYER_BULLET_DAMAGE	20		//普通子弹伤害
#define		BOMB_DAMAGE				40		//炮弹伤害
#define		LASER_DAMAGE			80		//激光伤害
#define		NUCLEAR_WEAPON_DAMAGE	80		//核弹伤害

//伤害范围
#define		BULLET_DAMAGE_RANGE				0		//子弹伤害范围
#define		BOMB_DAMAGE_RANGE				10		//炮弹伤害范围
#define		NUCLEAR_WEAPON_DAMAGE_RANGE		40		//核武器伤害范围

//技能CD 时间
#define		FIRE_BULLET_CD			2				//发射子弹的CD时间 
#define		FIRE_BOMB_CD			15				//发射炮弹CD
#define		SLIDE_CD				10				//滑步CD时间
#define		ULTIMATE_CD				65				//终极武器冷却CD


//z-order 定义
#define		TANK_Z_ORDER					4		//坦克z-order
#define		BULLET_Z_ORDER					4		//炮弹 z-order
#define		TREE_Z_ORDER					5		//树 z-order


#define		PLAYER_NAME				"player"//玩家名
//文件路径
