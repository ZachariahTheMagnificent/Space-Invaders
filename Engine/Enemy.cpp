#include "Enemy.h"

Enemy::Enemy(const int in_x, const int in_y) {
	posX = in_x;
	posY = in_y;
}

void Enemy::Draw(Graphics& gfx) const {
	for(int y = posY; y < posY + HEIGHT; ++y) {
		for(int x = posX; x < posX + WIDTH; ++x) {
			gfx.PutPixel(x, y, Colors::Green);
		}
	}
}

void Enemy::Update() {

}

int Enemy::GetX() const {
	return posX;
}

int Enemy::GetY() const {
	return posY;
}