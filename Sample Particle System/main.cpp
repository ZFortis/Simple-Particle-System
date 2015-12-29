#include "SDL.h"
#include"SDL_image.h"
#include"SDL_Sprite.h"
#include"Particle.h"
#include"ParticleManage.h"
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<time.h>
#include<cmath>

const int SCREEN_WIDTH = 640;
const int SCREEN_HIGHT = 480;
const int MAX_COUNT = 50;
int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = SDL_CreateWindow("Snake", 500, 100, SCREEN_WIDTH, SCREEN_HIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer*renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_Event e;
	ParticleManage pM;
	Particle p;
	bool quite = false;
	int mouseX=0, mouseY=0;
	p.loadImage(renderer, "./res/particle_r.png");
	p.setSprite(1, 10, 10);

	while (!quite)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				quite = true;
			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				if (e.button.button == SDL_BUTTON_LEFT)
				{
					for (int i = 0; i < MAX_COUNT; i++)
					{
						SDL_GetMouseState(&mouseX, &mouseY);
						p.setRandomMax(50,200);
						p.setRandomDirection();
						p.setSpritePosition(mouseX, mouseY);
						p.setLive();
						pM.addParticle(p);
					}
				}
			}
		}
		if (quite)
			continue;

		pM.moveEveryParticle();
		SDL_RenderClear(renderer);
		pM.drawEveryParticle(renderer);
		SDL_RenderPresent(renderer);
		pM.deleteParticle();
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	//ÍË³öSDL 
	SDL_Quit();
	return 0;
}