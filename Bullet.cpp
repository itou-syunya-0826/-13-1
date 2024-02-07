#include "Bullet.h"


Bullet::Bullet()
{
	posX_ = 100;
	posY_ = 100;
	radius_ = 16;
	speed_ = 8;
	IsShot_ = false;
	collision_ = new Collision;
}

Bullet::~Bullet(){
	delete collision_;
}

void Bullet::Draw()
{
	if (IsShot_ == true) {
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, WHITE, kFillModeSolid);
	}
}

void Bullet::Move()
{

	if (IsShot_ == true) {
		posY_ -= speed_;
	}
	if (posY_ < 0) {
		IsShot_ = false;
	}

}

void Bullet::SetIsShot(bool IsShot) {
	IsShot_ = IsShot;
}

void Bullet::SetPos(int posX, int posY){
	posX_ = posX;
	posY_ = posY;
}

void Bullet::IsHit(Enemy* enemy) {
	if (collision_->Box(enemy->GetPosX(), enemy->GetPosY(), enemy->GetRadius(), posX_, posY_, radius_)) {
		Enemy::IsAlive = false;
	}
}

