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
	//�������
	void addParticle(Particle p);
	//ɾ������
	void deleteParticle();
	//�ƶ�ÿ������
	void moveEveryParticle();
	//����ÿ������
	void drawEveryParticle(SDL_Renderer*renderer);

private:
	//��������
	vector<Particle> particleVec;
};

