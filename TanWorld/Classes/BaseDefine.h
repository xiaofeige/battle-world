////////////////////////////////////////////////////////////////////////////////////////
//
//								basic defenition of game
//
////////////////////////////////////////////////////////////////////////////////////////

//��������ǩ
#define		PLAYER_TAG				1001	//��ұ�ǩ
#define		ENEMY_TAG				1002	//�з���ǩ
#define		MAP_BARRIAR_TAG			1003	//��ͼ�ϰ����ǩ
#define		PLAYER_BULLET_TAG		1004	//����ӵ���ǩ
#define		ENEMY_BULLET_TAG		1005	//�з�
#define		EDGE_BOX_TAG			1006	//��Χǽ��ǩ
#define		MAP_POOL_TAG			1007	//��ͼ�к�����ǩ


//�����������
#define		UNITIVE_MASK			0xffffffff	//ͨ����ײ����
#define		POOL_MASK				0x00000000	//������ײ����

//���������Ⱥ
#define		WEAPON_GROUP			1			//������Ⱥ
#define		PLAYER_GROUP			2			//�����Ⱥ
#define		ENEMY_GROUP				2

//�ӵ��˺�
#define		PLAYER_ENEMY_CONTACT	40		//��Һ͵з���ײ���˺�
#define		ENEMY_BULLET_DAMAGE		20		//�з��ӵ��˺�
#define		PLAYER_BULLET_DAMAGE	20		//��ͨ�ӵ��˺�
#define		BOMB_DAMAGE				40		//�ڵ��˺�
#define		LASER_DAMAGE			80		//�����˺�
#define		NUCLEAR_WEAPON_DAMAGE	80		//�˵��˺�

//�˺���Χ
#define		BULLET_DAMAGE_RANGE				0		//�ӵ��˺���Χ
#define		BOMB_DAMAGE_RANGE				10		//�ڵ��˺���Χ
#define		NUCLEAR_WEAPON_DAMAGE_RANGE		40		//�������˺���Χ

//����CD ʱ��
#define		FIRE_BULLET_CD			2				//�����ӵ���CDʱ�� 
#define		FIRE_BOMB_CD			15				//�����ڵ�CD
#define		SLIDE_CD				10				//����CDʱ��
#define		ULTIMATE_CD				65				//�ռ�������ȴCD


//z-order ����
#define		TANK_Z_ORDER					4		//̹��z-order
#define		BULLET_Z_ORDER					4		//�ڵ� z-order
#define		TREE_Z_ORDER					5		//�� z-order


#define		PLAYER_NAME				"player"//�����
//�ļ�·��
