#pragma once
#include "raylib.h"
#include <cmath>
class Particule
{
private:
	float mEffectDuration;
	float mLifeTime;
	float mRadius;
	Vector2 mVelocity;
	Vector2 mPos;
	Color mColor;
	bool mIsDestroyed;
	float mSpeed;
public:
	Particule();
	Particule(float initialRadius, Vector2 initialVelocity, Vector2 initialPos, Color initialColor, float lifeTime, float initialSpeed);
	~Particule();
	void Update();
	void Draw();
	void Move(float particuleScaleFactor, float particuleSpeedFactor);
	float GetParticuleRadius();
	Vector2 GetParticuleSpeed();
	Vector2 GetParticulePos();
	Color GetParticuleColor();
	void SetSpeed(float newSpeed);
	Vector2 Normalize(Vector2 vector);
};

