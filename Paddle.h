#pragma once
#include "raylib.h"
class Paddle
{
private:
	Rectangle mRectangle;
	Vector2 mPos;
	Vector2 mSpeed;
public:
	Paddle();
	Paddle(Rectangle rectangle, Vector2 initialPos);
	~Paddle();
	void Load();
	void Start();
	void Update();
	void Draw();
	void Unload();
	Rectangle GetRectangle();
	Vector2 GetPos();
	Vector2 GetSpeed();
};

