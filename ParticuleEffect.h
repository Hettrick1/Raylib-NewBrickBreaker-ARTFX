#pragma once
#include "raylib.h"
#include "Particule.h"
#include "ParticuleTypeEnum.h"
#include <vector>

class ParticuleEffect
{
private:
	std::vector<Particule> mParticuleGroup;
	Vector2 mParticuleEffectPos;
	bool mLoopEffect;
	ParticuleType mType;
public:
	ParticuleEffect();
	ParticuleEffect(bool loopEffect, ParticuleType type);
	~ParticuleEffect();
	void Update();
	void Draw();
	void PlayEffect(Vector2 particuleEffectPos, int amount);
	void CreateParticules(int amount);
};

