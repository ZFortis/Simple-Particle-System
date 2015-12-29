#pragma once
#include "SDL_Sprite.h"
#include<cstdlib>
#include<ctime>
#include<random>
class Particle :
	public SDL_Sprite
{
public:
	Particle();
	~Particle();

public:
	void setRandomMax(int min, int max);
	void setRandomDirection();
	void moveParticle();
	void setLive();
	void setDead();
	bool ifLive();
	void killParticle();

private:
	int vx;
	int vy;
	int oldX;
	int oldY;
	int max;
	static int addseed;
	bool flag;
};

