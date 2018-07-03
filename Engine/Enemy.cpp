#include "Enemy.h"
#include "Game.h"

int Enemy::horSpeed = 1;
int Enemy::vertSpeed = 0;

Enemy::Enemy(const int in_x, const int in_y) {
	posX = in_x;
	posY = in_y;
}

Enemy::~Enemy() {

}

void Enemy::Draw(Graphics& gfx) const {
	gfx.DrawRect(posX, posY, WIDTH, HEIGHT, Colors::Yellow);
}

int Enemy::UpdatePosition() {
	//posX += horSpeed;
	//posY += vertSpeed;
	//vertSpeed = 0;

	return toBeDeleted;
}

void Enemy::UpdateSpeed() {
	if(posX + WIDTH >= Graphics::ScreenWidth - Game::X_BORDER || posX <= Game::X_BORDER) {
		horSpeed = -horSpeed;
		vertSpeed = 2;
	}
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
