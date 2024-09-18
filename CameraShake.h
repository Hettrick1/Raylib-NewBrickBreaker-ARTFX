#pragma once

#include "raylib.h"

#include <iostream>
#include <cmath>

class CameraShake
{
private:
	Camera2D* mCamera;
	float mTimer;
	float mDuration;
	float mShakeForce;
	float mShakeAmplitude;
	float mMaxShakeForce;
	float mResetRotationSpeed;
	bool mIsPlaying;
	Vector2 mInitialTarget;
public:
	CameraShake();
	CameraShake(Camera2D* camera);
	~CameraShake();
	void Update();
	void Draw();
	Vector2 RandomGradient(int ix, int iy);
	float DotGridGradient(int ix, int iy, float x, float y);
	float Interpolate(float a0, float a1, float w);
	float Perlin(float x, float y);
	void Play();
	void AddShakeForce(float shakeForce);
	bool GetIsPlaying();
	void SetIsPlaying(bool isPlaying);
	void ResetTimer();
	float Lerp(float a, float b, float t);
};

