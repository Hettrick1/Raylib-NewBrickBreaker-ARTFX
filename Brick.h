#pragma once
#include "raylib.h"
#include "Ball.h"
#include "ParticuleEffect.h"
#include "ParticuleTypeEnum.h"

#include <iostream>
class Brick
{
private:
	Rectangle mBrickRectangle;
	Vector2 mMapCoordinate;
	Color mColor;
	int mLife;
	bool mIsDestroyed;
	Ball* mBallRef;
	ParticuleEffect mExplosion;
public:
	Brick();
	Brick(Rectangle brickRectangle, Vector2 mapCoordinates, int lifes, Color color, Ball* ballRef);
	~Brick();
	void Update();
	void Draw();
	void LooseLife();
	bool CheckCollisions();
	Rectangle GetBrickRectangle();
	Vector2 GetMapCoordinates();
	int GetLife();
};

