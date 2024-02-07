#pragma once
#include <Vector2.h>
#include <Novice.h>
#include "Bullet.h"

class Player
{

private:

	Vector2 pos_;
	int radius_;
	int speed_;
	bool IsShot_;
	Bullet* bullet_;

public:

	Player();
	void Draw();
	void Move(char* keys,char*preKeys);
	Bullet* GetBullet() { return bullet_; };
	Vector2 GetPos() { return pos_; };

};

