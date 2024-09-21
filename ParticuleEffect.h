#pragma once
#include "raylib.h"
#include "Particule.h"
#include "ParticuleTypeEnum.h"
#include <deque>
#include <iostream>

class ParticuleEffect
{
private:
	std::deque<Particule> mParticuleGroup;
	Vector2 mParticuleEffectPos;
	bool mLoopEffect;
	ParticuleType mType;
	int mParticuleAmount;
public:
	ParticuleEffect();
	ParticuleEffect(bool loopEffect, ParticuleType type);
	~ParticuleEffect();
	void Update();
	void Draw();
	void PlayEffect(Vector2 particuleEffectPos, int amount);
	void CreateParticules(int amount);
};

