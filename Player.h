#pragma once
#include "gameNode.h"
enum class MOVELR
{
	LEFT_WALK,
	RIGHT_WALK,
	LEFT_RUN,
	RIGHT_RUN,
	NON
};
enum class MOVEUD
{
	UP_WALK,
	DOWN_WALK,
	UP_RUN,
	DOWN_RUN,
	NON
};
class State;
class Boss;
class Enemy;
class Player : public gameNode
{
private:
	

	State* _State;//������ ����
	Boss* _Boss; //�������浹 ��ſ�
	Enemy* _Enemy;

	POINTFLOAT _DummyCen;//������ȯ�� ��ǥ�����(����)
	POINTFLOAT _DummyCenHit;//������ȯ�� ��ǥ(�ǰ�)
	image* _Shadow;//�׸����̹���
	POINTFLOAT _Center;//�׸��ڼ���
	MYRECT _ShadowRc;//�׸��ڷ�Ʈ
	MYRECT _PlayerHitRc;//�÷��̾��ǰ���

	MOVELR _MoveLR;//�̵��Լ����̳�
	MOVEUD _MoveUD;//�̵��Լ����̳�
	float _Speed;

	MYRECT _AttackRc1;
	MYRECT _AttackRc2;
	MYRECT _AttackRc3;
	MYRECT _AttackRcH;
	bool _Dap = false;
	int _DapMax = 0;
	MYRECT _DashAtt;

	float _Money = 0;
	float _Exp = 0;
	int _Level = 0;
	int _HitDmg = 0;
	int _Hp = 24;

	int _AttackCount = 0;
	int _AttCountTimer = 0;
	bool _AttCountOn = false;

	/// <�뽬>
	bool _LRun=false;
	int _LTime = 0;
	int _LClickTime = 0;
	bool _RRun=false;
	int _RTime = 0;
	int _RClickTime = 0;
	/// </�뽬>
	
	//����
	float _JumpStack = 0;
	float _JumpMax = 300;
	bool _Jump = false;
	bool _Fall = false;
	//����
	bool _Hit = false;
	int _HitStack = 0;
	bool _Down = false;
	bool _StandUp = false;
	bool _DashAttbool = false;

	//����
	bool _LGuard = false;
	bool _RGuard = false;
	
	//���Ⱚ
	bool _Left=false;

	//�ǰ� ������
	bool _HitD = false;

	//�ȼ�Ž��� ���κ�
	int _ProbeL;
	int _ProbeR;
	int _ProbeT;
	int _ProbeB;
	string _MapName = "Stage1_1_Pixel";
	float _MapX,_MapY;

public:

	Player();
	virtual ~Player() {};

	virtual void PlayerImageAniStting();
	//�÷��̾� �̹��� �ִϸ��̼� ���� �Լ�


	virtual HRESULT Init();
	virtual void Update();
	virtual void Release();
	virtual void Render();
	virtual void DebugRender();
	virtual void PlayerKeyMove();
	virtual void MoveUpdate();
	virtual void AttackUpdate();
	virtual void DashUpdate();
	virtual void DashAttUpdate();
	virtual void JumpUpdate();
	virtual void HitUpdate();
	virtual void DownUpdate();
	virtual void StandUpUpdate();
	virtual void BossAndPlayerCol();
	virtual void GuardOff();
	virtual void AttCountTimer();
	virtual void RightHitReaction();
	virtual void LeftHitReaction();
	virtual void RightDownReaction();
	virtual void LeftDownReaction();
	virtual void PixelCol();
	virtual void DapMove();
	virtual void HitDUpDate();


	virtual void Walk();
	virtual void Attack1();
	virtual void Attack2();
	virtual void Attack3();
	virtual void StandUp();
	virtual void Skill1();
	virtual void Skill2();
	virtual void Guard();
	virtual void GameOver();
	virtual void DiveAttack();
	virtual void Default();


	//�浹ó����//
	inline bool GetPlayerDirection() { return _Left; }	//�÷��̾��¿����
	inline float GetShadowCenterX() { return _Center.x; }//�׸��ڼ���X
	inline float GetShadowCenterY() { return _Center.y; }//�׸��ڼ���Y
	inline POINTFLOAT GetShadowCenterPoint() { return _Center; }//�׸��ڼ�������Ʈ
	inline MYRECT GetShadowRect() { return _ShadowRc; }		//�÷��̾�׸��ڷ�Ʈ(����)
	inline MYRECT GetPlayerRect() { return _PlayerHitRc; } //�÷��̾��ǰݷ�Ʈ
	inline int GetAttackCount() { return _AttackCount; }//�޺�����ī��Ʈ��
	inline MYRECT GetAttackRC1() { return _AttackRc1; }//�޺���Ÿ1����Ʈ
	inline MYRECT GetAttackRC2() { return _AttackRc2; }//�޺���Ÿ2����Ʈ
	inline MYRECT GetAttackRC3() { return _AttackRc3; }//�޺���Ÿ3����Ʈ
	inline MYRECT GetAttackRCH() { return _AttackRcH; }//�㸮����ű��Ʈ
	inline MYRECT GetAttackRCDash() { return _DashAtt; }//��Ʈ
	//�浹ó����//



	///UI�� ////
	inline int GetPlayerLevel() { return _Level; }//�÷��̾��
	inline float GetPlayerMoney() { return _Money; }//�÷��̾������
	inline float GetPlayerHp() { return _Hp; }//�÷��̾�ü��
	inline float GetPlayerExp() { return _Exp; }//�÷��̾����ġ
	///UI�� ////



	
	inline void SetPlayerLevel(int level) { _Level = level; }//�÷��̾��
	inline void SetPlayerMoney(float money) { _Money = money; }//�÷��̾������
	inline void SetPlayerHp(float hp) { _Hp -= hp; }//�÷��̾�ü��
	inline void SetPlayerExp(float exp) { _Exp += exp; }//�÷��̾����ġ
	inline void SetAttackCount(int count) { _AttackCount += count; }//�÷��̾� �޺����� ī��Ʈ �ǰݴ��Ҷ����� 1�� �־��ּ���
	inline void SetCenterX(float x) { _Center.x += x; }
	inline void SetCenterY(float y) { _Center.y += y; }
	inline void SetCenterX1(float x) { _Center.x = x; }
	inline void SetCenterY1(float y) { _Center.y = y; }

	inline void SetShadowCenterX(POINTFLOAT XY) {
		_Center.x = XY.x;
		_Center.y = XY.y;
	}
	inline void SetBossMemoryAddressLink(Boss* b) { _Boss = b; }
	inline void SetEnemyMemoryAddressLink(Enemy* e) { _Enemy = e; }
	
	//�ȼ��浹�� �̹��� �ִ°�
	inline void SetMapName(string mapname) { _MapName = mapname; }
	void SetMapX(float x) { _MapY = x; }
	void SetMapY(float y) { _MapY = y; }
	void SetState(State* state);
};
