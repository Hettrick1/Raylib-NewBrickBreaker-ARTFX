#include "Ball.h"

Ball::Ball()
{
	mRadius = 0;
	mPos = { 0, 0 };
	mSpeed = { 0, 0 };
}

Ball::Ball(int radius, Vector2 initialPos, Vector2 initialSpeed)
{
	mRadius = radius;
	mPos = initialPos;
	mSpeed = initialSpeed;
}

Ball::~Ball()
{
}

void Ball::Load()
{
}

void Ball::Start()
{
}

void Ball::Update()
{
	mPos.x += mSpeed.x * GetFrameTime();
	mPos.y += mSpeed.y * GetFrameTime();
	if (mPos.x - mRadius < 0 || mPos.x + mRadius > GetScreenWidth()) {
		mSpeed.x *= -1;
	}
	else if (mPos.y - mRadius < 0 || mPos.y + mRadius > GetScreenHeight()) {
		mSpeed.y *= -1;
	}
	if (mPos.y + mRadius / 2 >= mPlayerPaddle->GetRectangle().y && mPos.x - mRadius / 2 > mPlayerPaddle->GetRectangle().x && mPos.x + mRadius / 2 < mPlayerPaddle->GetRectangle().x + mPlayerPaddle->GetRectangle().width)
	{
		float collisionPosition = (mPos.x - (mPlayerPaddle->GetRectangle().x + mPlayerPaddle->GetRectangle().width / 2));

		float newSpeedY = mMaxSpeed.x * collisionPosition / (mPlayerPaddle->GetRectangle().width / 2);

		mSpeed.x = newSpeedY;
		mSpeed.y *= -1;
	}
	if (mPos.y > mPlayerPaddle->GetRectangle().y) {
		mPos = { 540, 400 };
		mSpeed = { 0, 300 };
	}
}

void Ball::Draw()
{
	DrawCircle(mPos.x, mPos.y, mRadius, RED);
}

void Ball::Unload()
{
}

int Ball::GetRadius()
{
	return 0;
}

Vector2 Ball::GetPos()
{
	return Vector2();
}

Vector2 Ball::GetSpeed()
{
	return Vector2();
}

void Ball::ReferencePlayerPaddle(Paddle* playerPaddle)
{
	playerPaddle = mPlayerPaddle;
}
