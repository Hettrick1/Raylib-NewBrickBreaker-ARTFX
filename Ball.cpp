#include "Ball.h"

Ball::Ball()
{
	mScore = 0;
	mRadius = 0;
	mPos = { 0, 0 };
	mSpeed = { 0, 0 };
	mMaxSpeed = { 300, 300 };
	mPlayerPaddle = nullptr;
	mPlayerCamera = nullptr;
	mShake = CameraShake(mPlayerCamera);
}

Ball::Ball(int radius, Vector2 initialPos, Vector2 initialSpeed, Camera2D* playerCamera)
{
	mScore = 0;
	mRadius = radius;
	mPos = initialPos;
	mSpeed = initialSpeed;
	mMaxSpeed = { 500, 500 };
	mPlayerPaddle = nullptr;
	mPlayerCamera = playerCamera;
	mExplosion = ParticuleEffect(false, ParticuleType::Explosion);
	mShockWave = ParticuleEffect(false, ParticuleType::ShockWave);
	mShake = CameraShake(mPlayerCamera);
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
	mExplosion.Update();
	mShockWave.Update();
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
			mExplosion.PlayEffect(mPos, 80);
			mShockWave.PlayEffect(mPos, 120);
			mPos = { 560, 400 };
			mSpeed = { 0, 500 };
			mShake.SetIsPlaying(true);
			mShake.ResetTimer();
			mShake.AddShakeForce(50);
			mPlayerPaddle->SetPaddlePos({ (float)(GetScreenWidth() / 2.0 - 75), (float)(GetScreenHeight() - GetScreenHeight() / 10.0) });
		}

		mPlayerCamera->target = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 };

		if (mShake.GetIsPlaying()) {
			mShake.Play();
		}
	}
}

void Ball::Draw()
{
	mExplosion.Draw();
	mShockWave.Draw();
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

int Ball::GetScore()
{
	return mScore;
}

void Ball::AddScore(int score)
{
	mScore += score;
}

