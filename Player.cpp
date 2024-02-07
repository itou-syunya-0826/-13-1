#include "Player.h"

Player::Player() {
	pos_.x = 640;
	pos_.y = 550;
	radius_ = 32;
	IsShot_ = false;
	speed_ = 4;
	bullet_ = new Bullet;
}

void Player::Draw() {
	Novice::DrawEllipse((int)pos_.x, (int)pos_.y, radius_, radius_, 0.0f, GREEN, kFillModeSolid);
}

void Player::Move(char * keys,char*preKeys) {

	if (keys[DIK_W] || keys[DIK_UP]) {
		pos_.y -= speed_;
	}
	if (keys[DIK_S] || keys[DIK_DOWN]) {
		pos_.y += speed_;
	}
	if (keys[DIK_A] || keys[DIK_LEFT]) {
		pos_.x -= speed_;
	}
	if (keys[DIK_D] || keys[DIK_RIGHT]) {
		pos_.x += speed_;
	}

	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		bullet_->SetIsShot(true);
	}
	
}

