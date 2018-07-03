#include "Enemy.h"
#include "Game.h"
#include <random>

int Enemy::horSpeed = 1;
int Enemy::vertSpeed = 0;

Enemy::Enemy(const int in_x, const int in_y) {
	posX = in_x;
	posY = in_y;
}

void Enemy::OnDestroy() {
	std::mt19937 rng(time(0));
	std::uniform_int_distribution<int> xDist(posX, posX + WIDTH);
	std::uniform_int_distribution<int> yDist(posY, posY + HEIGHT);

	for(int i = 0; i < 3; ++i) {
		const int x = xDist(rng);
		const int y = yDist(rng);

		Game::CreateExplosion(x, y, 8, 3);
	}
}

void Enemy::Draw(Graphics& gfx) const {
	gfx.DrawRect(posX, posY, WIDTH, HEIGHT, Colors::Yellow);
}

void Enemy::Update() {
	//TODO: Move enemy around, shoot
}

void Enemy::MarkForDeletion() {
	toBeDeleted = true;
}

bool Enemy::IsDead() const {
	return toBeDeleted;
}

int Enemy::GetX() const {
	return posX;
}

int Enemy::GetY() const {
	return posY;
}
