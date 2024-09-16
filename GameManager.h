#pragma once
#include "Paddle.h"
#include "Ball.h"

class GameManager
{
public:
	void Load();
	void Start();
	void Update();
	void Draw();
	void Unload();
private:
	Ball mBall;
	Paddle mPlayerPaddle;
};

