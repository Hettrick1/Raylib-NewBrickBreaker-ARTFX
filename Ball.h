#pragma once
#include "raylib.h"
#include "Paddle.h"
#include "CameraShake.h"
class Ball
{
private:
	int mScore;
	int mRadius;
	Vector2 mPos;
	Vector2 mSpeed;
	Vector2 mMaxSpeed;
	Paddle* mPlayerPaddle;
	Camera2D* mPlayerCamera;
	CameraShake mShake;

public:
	Ball();
	Ball(int radius, Vector2 initialPos, Vector2 initialSpeed, Camera2D* playerCamera);
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
	int GetScore();
	void AddScore(int score);
};

