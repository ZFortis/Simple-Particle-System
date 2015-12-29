#include "ParticleManage.h"


ParticleManage::ParticleManage()
{
}


ParticleManage::~ParticleManage()
{
}

void ParticleManage::addParticle(Particle p)
{
	particleVec.push_back(p);
}

void ParticleManage::deleteParticle()
{
	for (auto a = particleVec.begin(); a != particleVec.end();)
	{
		a->killParticle();
		if (particleVec.empty())
			break;
		if (!a->ifLive())
		{
			particleVec.erase(a);
		}
		else
		{
			a++;
		}
	}
}

void ParticleManage::moveEveryParticle()
{
	for (auto &a : particleVec)
	{
		a.moveParticle();
	}
}

void ParticleManage::drawEveryParticle(SDL_Renderer*renderer)
{
	for (auto &a : particleVec)
	{
		a.textureRenderer(renderer);
	}
}