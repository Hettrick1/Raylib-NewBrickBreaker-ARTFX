#include "Brick.h"

Brick::Brick()
{
    mBrickRectangle = Rectangle();
    mMapCoordinate = Vector2();
    mColor = Color();
    mLife = 0;
    mIsDestroyed = true;
	mBallRef = nullptr;
	mPlayerCamera = nullptr;
	mShake = CameraShake(mPlayerCamera);
}

Brick::Brick(Rectangle brickRectangle, Vector2 mapCoordinates, int lifes, Color color, Ball* ballRef, Camera2D* playerCamera)
{
    mBrickRectangle = brickRectangle;
    mMapCoordinate = mapCoordinates;
    mColor = color;
    mLife = lifes;
    mIsDestroyed = false;
	mBallRef = ballRef;
	mExplosion = ParticuleEffect(false, ParticuleType::BrickDestruction, mColor);
	mPlayerCamera = playerCamera;
	mShake = CameraShake(mPlayerCamera);
}

Brick::~Brick()
{
}

void Brick::Update()
{
	mExplosion.Update();
	if (!mIsDestroyed) {
		if (CheckCollisions()) {
			if (mBallRef->GetPos().x - (mBallRef->GetRadius() + 2) < mBrickRectangle.x) { // gauche
				mColor = RED;
				mBallRef->SetPos(Vector2{ mBrickRectangle.x - mBallRef->GetRadius() , mBallRef->GetPos().y });
				mBallRef->SetSpeed(Vector2{ -200, mBallRef->GetSpeed().y });
				LooseLife();
			}
			else if (mBallRef->GetPos().x + (mBallRef->GetRadius() - 2) > mBrickRectangle.x + mBrickRectangle.width) { // droite
				mColor = RED;
				mBallRef->SetPos(Vector2{ mBrickRectangle.x + mBrickRectangle.width + mBallRef->GetRadius() , mBallRef->GetPos().y });
				mBallRef->SetSpeed(Vector2{ 200, mBallRef->GetSpeed().y });
				LooseLife();
			}
			else if (mBallRef->GetPos().y - (mBallRef->GetRadius() + 2) < mBrickRectangle.y) { // haut
				mColor = RED;
				mBallRef->SetPos(Vector2{ mBallRef->GetPos().x, mBrickRectangle.y - mBallRef->GetRadius() });
				mBallRef->SetSpeed(Vector2{ mBallRef->GetSpeed().x, -200 });
				LooseLife();
			}
			else if (mBallRef->GetPos().y + (mBallRef->GetRadius() - 2) > mBrickRectangle.y + mBrickRectangle.height) { // bas
				mColor = RED;
				mBallRef->SetPos(Vector2{ mBallRef->GetPos().x, mBrickRectangle.y + mBrickRectangle.height + mBallRef->GetRadius() });
				mBallRef->SetSpeed(Vector2{ mBallRef->GetSpeed().x, 200 });
				LooseLife();
			}
			mBallRef->AddScore(500);
			mShake.SetIsPlaying(true);
			mShake.ResetTimer();
			mShake.AddShakeForce(10);
		}
	}
	if (mPlayerCamera != nullptr) {
		mPlayerCamera->target = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 };

		if (mShake.GetIsPlaying()) {
			mShake.Play();
		}
	}
}

void Brick::Draw()
{
	mExplosion.Draw();
	if (!mIsDestroyed) {
		DrawRectangle(mBrickRectangle.x, mBrickRectangle.y, mBrickRectangle.width, mBrickRectangle.height, mColor);
	}
}

void Brick::LooseLife()
{
	mLife -= 1;
	if (mLife <= 0) {
		mIsDestroyed = true;
		mExplosion.PlayEffect({ mBrickRectangle.x + mBrickRectangle.width/2, mBrickRectangle.y + mBrickRectangle.height/2}, 80);
	}
}

bool Brick::CheckCollisions()
{
	return mBallRef->GetPos().x - mBallRef->GetRadius() < mBrickRectangle.x + mBrickRectangle.width && mBallRef->GetPos().x + mBallRef->GetRadius() > mBrickRectangle.x && mBallRef->GetPos().y - mBallRef->GetRadius() < mBrickRectangle.y + mBrickRectangle.height && mBallRef->GetPos().y + mBallRef->GetRadius() > mBrickRectangle.y;
}

Rectangle Brick::GetBrickRectangle()
{
	return mBrickRectangle;
}

Vector2 Brick::GetMapCoordinates()
{
	return mMapCoordinate;
}

int Brick::GetLife()
{
	return mLife;
}
