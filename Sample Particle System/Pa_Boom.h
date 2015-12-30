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
	//��������
	void loadParticle(Particle p);
	//���������������
	void setMaxCount(int max);
	//���ñ�ը��Χ
	void setBoomDistance(int min, int max);
	//��ը
	void showBoom(SDL_Renderer*renderer);
	//�����Ʊ�ը
	bool mouseControl(SDL_Event e);

private:
	//�����������
	int maxCount;
	//����
	Particle p;
	//���ӹ���
	ParticleManage pM;
	//����x����
	int mouseX;
	//����y����
	int mouseY;
	//��ը��С����
	int minDistance;
	//��ը������
	int maxDistance;
};

