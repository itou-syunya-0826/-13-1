#include "Enemy.h"


Enemy::Enemy(int posX,int posY)
{
	posX_ = posX;
	posY_ = posY;
	radius_ = 16;
	speed_ = 6;
	respawntimer_ = 120;
}

void Enemy::Draw()
{
	if (IsAlive == true) {
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, RED, kFillModeSolid);
	}
}

void Enemy::Move()
{
	posX_ += speed_;

	if (posX_+ radius_ > 1280) {
		speed_ *= -1;
	}

	if (posX_ - radius_ < 0) {
		speed_ *= -1;
	}

	if (IsAlive == false) {
		respawntimer_--;
	}

	if (respawntimer_ == 0) {
		IsAlive = true;
		respawntimer_ = 120;
	}
}
