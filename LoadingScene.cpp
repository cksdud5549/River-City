#include "stdafx.h"
#include "LoadingScene.h"
#include "progressBar.h"


LoadingScene::LoadingScene()
	: _background(nullptr), _loadingBar(nullptr),
	_currentCount(NULL)
{
}


LoadingScene::~LoadingScene()
{
}

HRESULT LoadingScene::init()
{
	_background = IMAGEMANAGER->addFrameImage("Loading", "Image/UI/Loading.bmp", 1600, 3600, 1, 4, false, RGB(255, 0, 255));

	_loadingBar = new progressBar;
	_loadingBar->init(0, WINSIZEY - 10, WINSIZEX, 10);
	_loadingBar->setGauge(0, 0);

	_x = _y = _count = 0;

	//�����带 ����Ϸ���
	CreateThread(
		NULL,				//�������� ���ȼӼ�(�ڽ������찡 �����Ҷ�) �ڵ�� �ڽ����� �θ����� �ľ�
		NULL,				//�������� ����ũ��(NULL�� �θ� ���ξ����� ũ��� ����)
		threadfunction,		//������ ����� �Լ� ��
		this,				//�������� �Ű�����(this�� �ϸ� �� Ŭ����)
		NULL,				//�������� Ư��(NULL�� �θ� �ٷ� ����)
		NULL				//�������� ���� �� �������� ID�� �Ѱ��ش� ������ NULL�� ��
	);


	return S_OK;
}

void LoadingScene::release()
{
	SAFE_DELETE(_loadingBar);
}

void LoadingScene::update()
{
	_loadingBar->update();
	_loadingBar->setGauge(_currentCount, LOADINGMAX);

	if (_currentCount == LOADINGMAX)
	{
		SCENEMANAGER->changeScene("VideoScene");
	}
	
	_count++;

	if (_count % 20 == 0)
	{
		_y++;
		if (_y > 3) _y = 0;
	}

}

void LoadingScene::render()
{
	_background->frameRender(getMemDC(), 0, 0, _x, _y);
	_loadingBar->render();
}

DWORD CALLBACK threadfunction(LPVOID lpParameter)
{
	LoadingScene* loadingHelper = (LoadingScene*)lpParameter;

	while (loadingHelper->_currentCount != LOADINGMAX)
	{
		SOUNDMANAGER->play("IntroMusic", 0.3f);

		//���� �Ȱɸ� �� ����...
		Sleep(1);

		loadingHelper->_currentCount++;
	}
	
	return 0;
}
