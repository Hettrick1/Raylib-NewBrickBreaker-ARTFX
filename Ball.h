#pragma once
#include "raylib.h"
#include "Paddle.h"
class Ball
{
private:
	int mRadius;
	Vector2 mPos;
	Vector2 mSpeed;
	Vector2 mMaxSpeed;
	Paddle* mPlayerPaddle;

public:
	Ball();
	Ball(int radius, Vector2 initialPos, Vector2 initialSpeed);
	~Ball();
	void Load();
	void Start();
	void Update();
	void Draw();
	void Unload();
	int GetRadius();
	Vector2 GetPos();
	Vector2 GetSpeed();
	void ReferencePlayerPaddle(Paddle* playerPaddle);
	void SetPos(Vector2 newPos);
	void SetSpeed(Vector2 newSpeed);
};

