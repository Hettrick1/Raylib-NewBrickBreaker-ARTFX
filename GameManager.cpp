#include "GameManager.h"

GameManager::GameManager()
{
	mScore = 0;
	mColones = 5;
	mIndex = 0;
	mLife = 5;
}

GameManager::~GameManager()
{
}

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
	for (int i = 0; i < mColones; i++) {
		for (int j = 0; j < 10; j++) {
			switch (mIndex)
			{
			case 0:
				mLevel1[i][j].Update(mBall);
				break;
			case 1:
				mLevel2[i][j].Update(mBall);
				break;
			case 2:
				mLevel3[i][j].Update(mBall);
				break;
			case 3:
				mLevel4[i][j].Update(mBall);
				break;
			};
		}
	}

	mBall.Update();
	mPlayerPaddle.Update();

	if (IsEverythingDestroyed()) {
		if (mColones < 12) {
			mColones += 3;
			mIndex += 1;
			InitializeGame();
		}
		else {
			mColones = 5;
			mIndex = 0;
			InitializeGame();
		}
	}
}

void GameManager::Draw()
{
	mBall.Draw();
	mPlayerPaddle.Draw();
	for (int i = 0; i < mColones; i++) {
		for (int j = 0; j < 10; j++) {
			switch (mIndex)
			{
			case 0:
				mLevel1[i][j].Draw();
				break;
			case 1:
				mLevel2[i][j].Draw();
				break;
			case 2:
				mLevel3[i][j].Draw();
				break;
			case 3:
				mLevel4[i][j].Draw();
				break;
			};
		}
	}
}

void GameManager::InitializeGame()
{
	Vector2 coordinates = { 40,0 };
	for (int i = 0; i < mColones; i++) {
		coordinates.x = 40;
		coordinates.y += 22;
		for (int j = 0; j < 10; j++) {
			Brick brick = Brick(Rectangle{ coordinates.x, coordinates.y, 98.4, 20 }, Vector2{ (float)i, (float)j }, 1, BLUE);
			switch (mIndex)
			{
			case 0:
				mLevel1[i][j] = brick;
				break;
			case 1:
				mLevel2[i][j] = brick;
				break;
			case 2:
				mLevel3[i][j] = brick;
				break;
			case 3:
				mLevel4[i][j] = brick;
				break;
			};
			coordinates.x += 100.4;
		}
	}
}

bool GameManager::IsEverythingDestroyed()
{
	for (int i = 0; i < mColones; i++) {
		for (int j = 0; j < 10; j++) {
			switch (mIndex)
			{
			case 0:
				if (mLevel1[i][j].GetLife() != 0) {
					return false;
				}
				break;
			case 1:
				if (mLevel2[i][j].GetLife() != 0) {
					return false;
				}
				break;
			case 2:
				if (mLevel3[i][j].GetLife() != 0) {
					return false;
				}
				break;
			case 3:
				if (mLevel4[i][j].GetLife() != 0) {
					return false;
				}
				break;
			};
		}
	}
	return true;
}

void GameManager::Unload()
{
}
