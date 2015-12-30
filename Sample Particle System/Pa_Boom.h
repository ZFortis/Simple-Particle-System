#pragma once
#include "SDL.h"
#include"SDL_image.h"
#include"SDL_Sprite.h"
#include"Particle.h"
#include"ParticleManage.h"

class Pa_Boom
{
public:
	Pa_Boom();
	~Pa_Boom();

public:
	//加载粒子
	void loadParticle(Particle p);
	//设置最大粒子数量
	void setMaxCount(int max);
	//设置爆炸范围
	void setBoomDistance(int min, int max);
	//爆炸
	void showBoom(SDL_Renderer*renderer);
	//鼠标控制爆炸
	bool mouseControl(SDL_Event e);

private:
	//最大粒子数量
	int maxCount;
	//粒子
	Particle p;
	//粒子管理
	ParticleManage pM;
	//鼠标的x坐标
	int mouseX;
	//鼠标的y坐标
	int mouseY;
	//爆炸最小距离
	int minDistance;
	//爆炸最大距离
	int maxDistance;
};

