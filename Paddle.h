#pragma once
#include "raylib.h"
class Paddle
{
private:
	Rectangle mRectangle;
	Vector2 mSpeed;
public:
	Paddle();
	Paddle(Rectangle rectangle);
	~Paddle();
	void Load();
	void Start();
	void Update();
	void Draw();
	void Unload();
	Rectangle GetRectangle() { return Rectangle{ mRectangle.x, mRectangle.y, mRectangle.width, mRectangle.height }; }
	Vector2 GetSpeed();
};

