#include "Paddle.h"

Paddle::Paddle()
{
    mRectangle = { 0, 0, 0, 0 };
    mSpeed = { 0, 0 };
}

Paddle::Paddle(Rectangle rectangle)
{
    mRectangle = rectangle;
    mSpeed = { 400, 0 };
}

Paddle::~Paddle()
{
}

void Paddle::Load()
{
}

void Paddle::Start()
{
}

void Paddle::Update()
{
    if ((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && mRectangle.x > 0) {
        mRectangle.x -= mSpeed.x * GetFrameTime();
    }
    if ((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && mRectangle.x < GetScreenWidth() - mRectangle.width) {
        mRectangle.x += mSpeed.x * GetFrameTime();
    }
}

void Paddle::Draw()
{
    DrawRectangle(mRectangle.x, mRectangle.y, mRectangle.width, mRectangle.height, WHITE);
}

void Paddle::Unload()
{
}

Vector2 Paddle::GetSpeed()
{
    return mSpeed;
}
