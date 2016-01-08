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
	//����λ�÷�Χ
	void setRandomMax(int min, int max);
	//�����������
	void setRandomDirection();
	//�ƶ�����
	void moveParticle();
	//�������Ӵ���
	void setLive();
	//������������
	void setDead();
	//�ж������Ƿ����
	bool ifLive();
	//ɱ��������Χ������
	void killParticle();

private:
	//�˶���x����
	int vx;
	//�˶���y����
	int vy;
	//���ӵ���ʱ��x����
	int oldX;
	//���ӵ���ʱ��y����
	int oldY;
	//������Զ�ľ���
	int max;
	//���ӵĴ���־
	bool flag;
};

