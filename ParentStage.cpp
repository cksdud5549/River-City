#include "stdafx.h"
#include "ParentStage.h"
#include "Player.h"
#include "AllObstacle.h"

ParentStage::ParentStage()
{
	
}

void ParentStage::release()
{
	//���ʹ� ������


	_RightExit.centerSet(30000, 30000, 0, 0);
	_LeftExit.centerSet(30000, 30000, 0, 0);
}

void ParentStage::update()
{
	IsColRightExit();
	IsColLefttExit();
	IsInEventArea();
	EventScript();

	
}

void ParentStage::render()
{
	
	
	 
}

bool ParentStage::IsColRightExit()
{
	if (isCollision(_Player->GetShadowRect(), _RightExit) && _IsOnceClear)return true;
	return false;
}

bool ParentStage::IsColLefttExit()
{
	if (isCollision(_Player->GetShadowRect(), _LeftExit) && _IsOnceClear)return true;
	return false;
}

bool ParentStage::IsInEventArea()
{
	if (isCollision(_Player->GetShadowRect(), _EventArea) && !_IsOnceClear)return true;
	return false;
}



