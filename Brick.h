#pragma once
#include "raylib.h"
#include "Ball.h"

#include <iostream>
class Brick
{
private:
	Rectangle mBrickRectangle;
	Vector2 mMapCoordinate;
	Color mColor;
	int mLife;
	bool mIsDestroyed;
public:
	Brick();
	Brick(Rectangle brickRectangle, Vector2 mapCoordinates, int lifes, Color color);
	~Brick();
	void Update(Ball& ball);
	void Draw();
	void LooseLife();
	bool CheckCollisions(Ball& ball);
	Rectangle GetBrickRectangle();
	Vector2 GetMapCoordinates();
	int GetLife();
};

