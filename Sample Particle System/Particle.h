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
	//设置位置范围
	void setRandomMax(int min, int max);
	//设置随机方向
	void setRandomDirection();
	//移动粒子
	void moveParticle();
	//设置粒子存在
	void setLive();
	//设置粒子死亡
	void setDead();
	//判断粒子是否存在
	bool ifLive();
	//杀死超出范围的粒子
	void killParticle();

private:
	//运动的x方向
	int vx;
	//运动的y方向
	int vy;
	//粒子诞生时的x坐标
	int oldX;
	//粒子诞生时的y坐标
	int oldY;
	//粒子最远的距离
	int max;
	//粒子的存活标志
	bool flag;
};

