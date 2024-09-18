#include "GameManager.h"

void GameManager::Load()
{
	mPlayerPaddle = Paddle({ (float)(GetScreenWidth() / 2.0 - 60), (float)(GetScreenHeight() - GetScreenHeight() / 10.0), 150, 25}); 
	mBall = Ball(15, { 600, 400 }, { 0, 300 });
	mBall.ReferencePlayerPaddle(&mPlayerPaddle);
}

void GameManager::Start()
{
}

void GameManager::Update()
{
	mBall.Update();
	mPlayerPaddle.Update();
}

void GameManager::Draw()
{
	mBall.Draw();
	mPlayerPaddle.Draw();
}

void GameManager::Unload()
{
}
