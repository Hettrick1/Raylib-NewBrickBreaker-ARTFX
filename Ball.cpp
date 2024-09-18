#include "Ball.h"

Ball::Ball()
{
	mRadius = 0;
	mPos = { 0, 0 };
	mSpeed = { 0, 0 };
	mMaxSpeed = { 200, 200 };
	mPlayerPaddle = nullptr;
}

Ball::Ball(int radius, Vector2 initialPos, Vector2 initialSpeed)
{
	mRadius = radius;
	mPos = initialPos;
	mSpeed = initialSpeed;
	mMaxSpeed = { 200, 200 };
	mPlayerPaddle = nullptr;
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
	if (mPos.x - mRadius < 2 || mPos.x + mRadius > GetScreenWidth() - 2) {
		mSpeed.x *= -1;
	}
	else if (mPos.y - mRadius < 2 || mPos.y + mRadius > GetScreenHeight() - 2) {
		mSpeed.y *= -1;
	}
	if (mPlayerPaddle != nullptr) {
		if (mPos.y + mRadius / 2 >= mPlayerPaddle->GetRectangle().y - 5 && mPos.x - mRadius / 2 > mPlayerPaddle->GetRectangle().x - 15 && mPos.x + mRadius / 2 < mPlayerPaddle->GetRectangle().x + mPlayerPaddle->GetRectangle().width + 15)
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
	return mRadius;
}

Vector2 Ball::GetPos()
{
	return mPos;
}

Vector2 Ball::GetSpeed()
{
	return mSpeed;
}

void Ball::ReferencePlayerPaddle(Paddle* playerPaddle)
{
	mPlayerPaddle = playerPaddle;
	
}

void Ball::SetPos(Vector2 newPos)
{
	mPos = newPos;
}

void Ball::SetSpeed(Vector2 newSpeed)
{
	mSpeed = newSpeed;
}

