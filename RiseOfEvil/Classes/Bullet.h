#pragma once
#include "cocos2d.h"
#include "Monster.h"
#define ARROW_BULLET 1
#define MAGIC_BULLET 2
#define SLOW_BULLET 3
#define BOMBARD_BULLET 4
#define BARRACKS_BULLET 5
using namespace cocos2d;
class Bullet
{
private:
	Sprite * m_sprite;
	Layer* m_layer;
	ParticleSystemQuad * explotion_arrow;
	ParticleSystemQuad * explotion_magic;
	ParticleSystemQuad * explotion_slow;
	ParticleSystemQuad * explotion_bombard;
	Monster *monsterBeHit;
	int damageOfHit;
	int bullet_type;
	vector<Monster*> listOfCurrentMonster;
	int typeOfTower;
public:
	void Init();
	Bullet(Layer* layer, int type);
	void Update(float deltaTime);
	void Move(Monster*,int,vector<Monster*>,int);
	void AfterShoot();
	Sprite* GetSprite();
	void Disappear();
	void damageToMonster(Monster*);
	//Point GetPosBullet();
};