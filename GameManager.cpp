#include "GameManager.h"


Camera2D camera = { 0 };


GameManager::GameManager()
{
	mColones = 5;
	mIndex = 0;
}

GameManager::~GameManager()
{
}

void GameManager::Load()
{
	mPlayerPaddle = Paddle({ (float)(GetScreenWidth() / 2.0 - 75), (float)(GetScreenHeight() - GetScreenHeight() / 10.0), 150, 25}); 
	mBall = Ball(15, { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2}, { 0, 500 }, &camera);
	mBall.ReferencePlayerPaddle(&mPlayerPaddle);
	camera.target = Vector2{ (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2};
	camera.offset = Vector2{ (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 };
	camera.rotation = 0;
	camera.zoom = 1.0f;
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
				mLevel1[i][j].Update();
				break;
			case 1:
				mLevel2[i][j].Update();
				break;
			case 2:
				mLevel3[i][j].Update();
				break;
			case 3:
				mLevel4[i][j].Update();
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
	BeginMode2D(camera);
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
	EndMode2D();
	DrawText(TextFormat("Score : %i", mBall.GetScore()), 20, GetScreenHeight() - 50, 40, WHITE);
}

void GameManager::InitializeGame()
{
	mBall.SetPos({ 560, 400 });
	Vector2 coordinates = { 40,0 };
	for (int i = 0; i < mColones; i++) {
		coordinates.x = 40;
		coordinates.y += 22;
		for (int j = 0; j < 10; j++) {
			Brick brick = Brick(Rectangle{ coordinates.x, coordinates.y, 98.4, 20 }, Vector2{ (float)i, (float)j }, 1, BLUE, &mBall);
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
