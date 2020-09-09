#pragma once
#include "gameNode.h"

class pixelCollsion : public gameNode
{
private:
	image* _hill;	//��� �̹���
	image* _ball;	//�� �̹���
	RECT _rc;		//���� ����� ��Ʈ
	float _x, _y;	//���� ������ǥ
	RECT _rc2;
	RECT _L; // Ž����Ʈ
	RECT _R;
	RECT _T;
	RECT _B;
	float speed;
	float jumpPower;
	float gravity;
	int _probeT;	//Y�� Ž��
	int _probeB;	//X�� Ž��
	int _probeL;	//L�� Ž��
	int _probeR;	//R�� Ž��
	bool collision; // �ȼ����� �浹������
public:
	pixelCollsion();
	~pixelCollsion();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	bool PixelCollisionTest(string Imgname, float getPixelX, float getPixelY, int SetColorR, int SetColorG, int SetColorB);
	void jump();
	void probeRectMake(float PlayerX, float playerY, float RectTop, float RectBottom, float RectLeft, float RectRight);
};

