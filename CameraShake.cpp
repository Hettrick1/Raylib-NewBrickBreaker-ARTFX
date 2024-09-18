#include "CameraShake.h"

CameraShake::CameraShake()
{

}

CameraShake::CameraShake(Camera2D* camera)
{
    mCamera = camera;
    mTimer = 0;
    mDuration = 0.3;
    mShakeForce = 0;
    mMaxShakeForce = 10;
    mShakeAmplitude = 30;
    mResetRotationSpeed = 6;
    mIsPlaying = false;
    mInitialTarget = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 };
}

CameraShake::~CameraShake()
{

}

void CameraShake::Update()
{

}

void CameraShake::Draw()
{

}

Vector2 CameraShake::RandomGradient(int ix, int iy) {
    const unsigned w = 8 * sizeof(unsigned);
    const unsigned s = w / 2;
    unsigned a = ix, b = iy;
    a *= 3284157443;

    b ^= a << s | a >> w - s;
    b *= 1911520717;

    a ^= b << s | b >> w - s;
    a *= 2048419325;
    float random = a * (3.14159265 / ~(~0u >> 1));

    Vector2 v;
    v.x = sin(random);
    v.y = cos(random);

    return v;
}

float CameraShake::DotGridGradient(int ix, int iy, float x, float y) {
    Vector2 gradient = RandomGradient(ix, iy);

    float dx = x - (float)ix;
    float dy = y - (float)iy;

    return (dx * gradient.x + dy * gradient.y);
}

float CameraShake::Interpolate(float a0, float a1, float w)
{
    return (a1 - a0) * (3.0 - w * 2.0) * w * w + a0;
}

float CameraShake::Perlin(float x, float y) {
    int x0 = (int)x;
    int y0 = (int)y;
    int x1 = x0 + 1;
    int y1 = y0 + 1;

    float sx = x - (float)x0;
    float sy = y - (float)y0;

    float n0 = DotGridGradient(x0, y0, x, y);
    float n1 = DotGridGradient(x1, y0, x, y);
    float ix0 = Interpolate(n0, n1, sx);

    n0 = DotGridGradient(x0, y1, x, y);
    n1 = DotGridGradient(x1, y1, x, y);
    float ix1 = Interpolate(n0, n1, sx);

    float value = Interpolate(ix0, ix1, sy);

    return value;
}

void CameraShake::Play()
{
    mTimer += GetFrameTime();
    if(mTimer < mDuration) {
        float time = GetTime();
        float offsetFactorX = Perlin(time * mShakeAmplitude, 0);
        float offsetFactorY = Perlin(0, time * mShakeAmplitude);
        float rotationShakeFactor = Perlin(time * 10, 0);

        if (offsetFactorX > 1) offsetFactorX = 1;
        else if (offsetFactorX < -1) offsetFactorX = -1;

        if (offsetFactorY > 1) offsetFactorY = 1;
        else if (offsetFactorY < -1) offsetFactorY = -1;

        if (rotationShakeFactor > 1) rotationShakeFactor = 1;
        else if (rotationShakeFactor < -1) rotationShakeFactor = -1;

        float shake = mShakeForce / (mCamera->zoom*2);

        float offsetX = shake * offsetFactorX * 4;
        float offsetY = shake * offsetFactorY * 4;
        float angle = (shake / 5) * rotationShakeFactor * 2;

        if (offsetX > 80) offsetX = 80;
        else if (offsetX < -80) offsetX = -80;

        if (offsetY > 80) offsetY = 80;
        else if (offsetY < -80) offsetY = -80;

        if (angle > 5) angle = 5;
        else if (angle < -5) angle = -5;

        mCamera->target.x += offsetX;
        mCamera->target.y += offsetY;
        mCamera->rotation = angle;

        if (mShakeForce > 1) {
            mShakeForce -= mShakeForce / 10;
        }
    }
    else if (mCamera->rotation != 0){
        float newRot = Lerp(mCamera->rotation, 0, GetFrameTime() * mResetRotationSpeed);
        mCamera->rotation = newRot;
    }
    else {
        mCamera->rotation = 0;
        mTimer = 0;
        mIsPlaying = false;
    }
}

void CameraShake::AddShakeForce(float shakeForce)
{
    mShakeForce += shakeForce;
    if (mShakeForce > mMaxShakeForce) {
        mShakeForce = mMaxShakeForce;
    }
}

bool CameraShake::GetIsPlaying()
{
    return mIsPlaying;
}

void CameraShake::SetIsPlaying(bool isPlaying)
{
    mIsPlaying = isPlaying;
}

void CameraShake::ResetTimer()
{
    mTimer = 0;
}

float CameraShake::Lerp(float a, float b, float t)
{
    return (a + t * (b - a));
}