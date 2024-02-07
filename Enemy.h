#pragma once
#include <Novice.h>

class Enemy
{
private:

	int posX_;
	int posY_;
	int radius_;
	int speed_;
	int respawntimer_;
	
public:

	static bool IsAlive;

	Enemy(int posX,int posY);
	void Draw();
	void Move();
	int GetPosX() { return posX_; };
	int GetPosY() { return posY_; };
	int GetRadius() { return radius_; };

};

