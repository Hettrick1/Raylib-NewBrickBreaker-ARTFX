#include "Paddle.h"

Paddle::Paddle()
{
    mRectangle = { 0, 0, 0, 0 };
    mPos = { 0, 0 };
    mSpeed = { 0, 0 };
}

Paddle::Paddle(Rectangle rectangle, Vector2 initialPos)
{
    mRectangle = rectangle;
    mPos = initialPos;
    mSpeed = { 0, 0 };
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
}

void Paddle::Draw()
{
}

void Paddle::Unload()
{
}

Rectangle Paddle::GetRectangle()
{
    return Rectangle();
}

Vector2 Paddle::GetPos()
{
    return Vector2();
}

Vector2 Paddle::GetSpeed()
{
    return Vector2();
}
