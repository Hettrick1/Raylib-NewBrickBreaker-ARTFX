#include "Particule.h"

Particule::Particule()
{
	mRadius = 0;
	mSpeed = 0;
	mVelocity = { 0, 0 };
	mEffectDuration = 0;
	mLifeTime = 0;
	mIsDestroyed = true;
	mPos = { 0, 0 };
	mColor = BLANK;
}

Particule::Particule(float initialRadius, Vector2 initialVelocity, Vector2 initialPos, Color initialColor, float lifeTime, float initialSpeed)
{
	mRadius = initialRadius;
	mVelocity = initialVelocity;
	mPos = initialPos;
	mColor = initialColor;
	mEffectDuration = lifeTime;
	mLifeTime = 255 / mEffectDuration;
	mIsDestroyed = false;
	mSpeed = initialSpeed;
	mVelocity = Normalize(mVelocity);
	mVelocity.x *= mSpeed;
	mVelocity.y *= mSpeed;
}

Particule::~Particule()
{
}

void Particule::Update()
{
}

void Particule::Draw()
{
	if (!mIsDestroyed) {
		DrawCircle(mPos.x, mPos.y, mRadius, mColor);
	}
}

void Particule::Move(float particuleScaleFactor, float particuleSpeedFactor)
{
	mRadius += particuleScaleFactor * GetFrameTime();
	mVelocity.x += particuleSpeedFactor * GetFrameTime();
	mVelocity.y += particuleSpeedFactor * GetFrameTime();
	mPos.x += mVelocity.x * GetFrameTime();
	mPos.y += mVelocity.y * GetFrameTime();
	if (mEffectDuration > 0) {
		mEffectDuration -= GetFrameTime();
		if (mColor.a > 5) {
			mColor.a -= mLifeTime * GetFrameTime();;
		}
	}
	else {
		mIsDestroyed = true;
	}
}

float Particule::GetParticuleRadius()
{
	return mRadius;
}

Vector2 Particule::GetParticuleSpeed()
{
	return mVelocity;
}

Vector2 Particule::GetParticulePos()
{
	return mPos;
}

Color Particule::GetParticuleColor()
{
	return mColor;
}

Vector2 Particule::Normalize(Vector2 vector)
{
	float length = sqrt(vector.x * vector.x + vector.y * vector.y);
	if (length != 0) {
		return { vector.x / length, vector.y / length };
	}
	return vector;
}
