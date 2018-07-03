#include "Enemy.h"

Enemy::Enemy(const int in_x, const int in_y) {
	posX = in_x;
	posY = in_y;
}

void Enemy::Draw(Graphics& gfx) const {
	gfx.DrawRect(posX, posY, WIDTH, HEIGHT, Colors::Yellow);
}

int Enemy::Update() {
	return toBeDeleted;
}

void Enemy::MarkForDeletion() {
	toBeDeleted = true;
}

int Enemy::GetX() const {
	return posX;
}

int Enemy::GetY() const {
	return posY;
}
