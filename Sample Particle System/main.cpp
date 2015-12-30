#include "SDL.h"
#include"SDL_image.h"
#include"SDL_Sprite.h"
#include"Particle.h"
#include"ParticleManage.h"
#include"Pa_Boom.h"
#include<vector>


const int SCREEN_WIDTH = 640;
const int SCREEN_HIGHT = 480;
const int MAX_COUNT = 50;
int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = SDL_CreateWindow("Simple Particle System", 500, 100, SCREEN_WIDTH, SCREEN_HIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer*renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_Event e;
	ParticleManage pM;
	Particle p;
	Pa_Boom boom;
	bool quite = false;
	int mouseX=0, mouseY=0;
	p.loadImage(renderer, "./res/particle_r.png");
	p.setSprite(1, 10, 10);
	boom.setMaxCount(MAX_COUNT);
	boom.setBoomDistance(50, 200);
	while (!quite)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				quite = true;
			if (boom.mouseControl(e))
				boom.loadParticle(p);
		}
		if (quite)
			continue;

		boom.showBoom(renderer);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	//ÍË³öSDL 
	SDL_Quit();
	return 0;
}