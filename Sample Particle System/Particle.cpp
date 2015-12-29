#include "Particle.h"


Particle::Particle()
{
}


Particle::~Particle()
{
}

int Particle::addseed = 0;

void Particle::setRandomMax(int min, int max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(min, max);
	this->max = dis(gen);
}

void Particle::setRandomDirection()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 8);
	vx = dis(gen);
	vy = dis(gen);
	if (vx == 0 && vy == 0)
	{
		vx++;
		vy++;
	}
	uniform_int_distribution<> dis2(0, 3);
	int flag = dis2(gen);
	switch (flag)
	{
	case 0:vx *= (-1); break;
	case 1:vy *= (-1); break;
	case 2:vx *= (-1); vy *= (-1); break;
	default:
		break;
	}
}

void Particle::moveParticle()
{
	x += vx;
	y += vy;
}

void Particle::setLive()
{
	flag = true;
	oldX = x;
	oldY = y;
}

void Particle::setDead()
{
	flag = true;
}

bool Particle::ifLive()
{
	return flag;
}

void Particle::killParticle()
{
	if (((oldX - x)*(oldX - x) + (oldY - y)*(oldY - y)) >= max*max)
	{
		flag = false;
	}
}