#pragma once
#include<vector>
#include"Particle.h"
using namespace std;
class ParticleManage
{
public:
	ParticleManage();
	~ParticleManage();

public:
	void addParticle(Particle p);
	void deleteParticle();
	void moveEveryParticle();
	void drawEveryParticle(SDL_Renderer*renderer);

private:
	vector<Particle> particleVec;
};

