#include "ParticuleEffect.h"

ParticuleEffect::ParticuleEffect()
{
	mLoopEffect = false;
	mType = ParticuleType::Explosion;
	mParticuleEffectPos = { 0, 0 };
	mParticuleAmount = 0;
}

ParticuleEffect::ParticuleEffect(bool loopEffect, ParticuleType type)
{
	mLoopEffect = loopEffect;
	mType = type;
	mParticuleEffectPos = { 0, 0 };
	mParticuleAmount = 0;
}

ParticuleEffect::~ParticuleEffect()
{
}

void ParticuleEffect::Update()
{
	for (Particule& particule : mParticuleGroup) {
		switch (mType)
		{
		case ParticuleType::Explosion:
			particule.Move(-8, GetRandomValue(15, 30));
			break;
		case ParticuleType::ShockWave:
			particule.Move(-1, GetRandomValue(25, 40));
			break;
		case ParticuleType::BrickDestruction:
			particule.Move(-10, GetRandomValue(15, 30));
			break;
		}
	}
	if (!mParticuleGroup.empty() && mParticuleGroup[0].GetIsDestroyed()) {
		for (int i = 0; i < mParticuleAmount; i++) {
			mParticuleGroup.pop_front();
		}
	}
}

void ParticuleEffect::Draw()
{
	for (Particule& particule : mParticuleGroup) {
		particule.Draw();
	}
}

void ParticuleEffect::PlayEffect(Vector2 particuleEffectPos, int amount)
{
	mParticuleEffectPos = particuleEffectPos;
	mParticuleAmount = amount;
	CreateParticules(amount);
}

void ParticuleEffect::CreateParticules(int amount)
{
	switch (mType)
	{
	case ParticuleType::Explosion:
		for (int i = 0; i < amount; i++) {
			Particule particule = Particule((float)(GetRandomValue(15, 20)), { (float)(GetRandomValue(-50, 50)), (float)(GetRandomValue(-50, 50)) }, mParticuleEffectPos, RED, 0.8, GetRandomValue(10, 500));
			mParticuleGroup.push_back(particule);
		}
		break;
	case ParticuleType::ShockWave:
		for (int i = 0; i < amount; i++) {
			Particule particule = Particule((float)(GetRandomValue(10, 15)), { (float)(GetRandomValue(-50, 50)), (float)(GetRandomValue(-50, 50)) }, mParticuleEffectPos, Color{ 92, 10, 10, 255 }, 0.8, 600);
			mParticuleGroup.push_back(particule);
		}
		break;
	case ParticuleType::BrickDestruction:
		for (int i = 0; i < amount; i++) {
			Particule particule = Particule((float)(GetRandomValue(5, 10)), { (float)(GetRandomValue(-50, 50)), (float)(GetRandomValue(-50, 50)) }, mParticuleEffectPos, DARKBLUE, 0.4, GetRandomValue(10, 200));
			mParticuleGroup.push_back(particule);
		}
	}
}
