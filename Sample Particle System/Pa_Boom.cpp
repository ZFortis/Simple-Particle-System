#include "Pa_Boom.h"


Pa_Boom::Pa_Boom()
{
}


Pa_Boom::~Pa_Boom()
{
}

void Pa_Boom::loadParticle(Particle p)
{
	this->p = p;
	for (int i = 0; i < maxCount; i++)
	{
		p.setRandomMax(minDistance, maxDistance);
		p.setRandomDirection();
		p.setSpritePosition(mouseX, mouseY);
		p.setLive();
		pM.addParticle(p);
	}
}

void Pa_Boom::setMaxCount(int max)
{
	maxCount = max;
}

void Pa_Boom::setBoomDistance(int min, int max)
{
	maxDistance = max;
	minDistance = min;
}

void Pa_Boom::showBoom(SDL_Renderer*renderer)
{
	pM.moveEveryParticle();
	SDL_RenderClear(renderer);
	pM.drawEveryParticle(renderer);
	SDL_RenderPresent(renderer);
	pM.deleteParticle();
}

bool Pa_Boom::mouseControl(SDL_Event e)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (e.button.button == SDL_BUTTON_LEFT)
		{
			SDL_GetMouseState(&mouseX, &mouseY);
			return true;
		}
	}
	return false;
}