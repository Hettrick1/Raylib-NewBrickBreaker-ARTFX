#include "GameManager.h"

void GameManager::Load()
{
	mBall = Ball(10, { 600, 400 }, { 200, 200 });
	mPlayerPaddle = Paddle({})
}

void GameManager::Start()
{
}

void GameManager::Update()
{
	mBall.Update();
}

void GameManager::Draw()
{
	mBall.Draw();
}

void GameManager::Unload()
{
}
