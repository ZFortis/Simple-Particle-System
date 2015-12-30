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
	//添加粒子
	void addParticle(Particle p);
	//删除粒子
	void deleteParticle();
	//移动每个粒子
	void moveEveryParticle();
	//绘制每个粒子
	void drawEveryParticle(SDL_Renderer*renderer);

private:
	//粒子容器
	vector<Particle> particleVec;
};

