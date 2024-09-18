#pragma once
#include "Paddle.h"
#include "Ball.h"
#include "Brick.h"
#include "CameraShake.h"

class GameManager
{
private:
	int mColones;
	int mIndex;
	Ball mBall;
	Paddle mPlayerPaddle;
	Brick mLevel1[5][10];
	Brick mLevel2[8][10];
	Brick mLevel3[11][10];
	Brick mLevel4[14][10];
public:
	GameManager();
	~GameManager();
	void Load();
	void Start();
	void Update();
	void Draw();
	void InitializeGame();
	bool IsEverythingDestroyed();
	void Unload();
};

