#include "Projectile.h"
#include "Game.h"

Projectile::Projectile(int in_x, int in_y, int in_id) {
	posY = in_y - HEIGHT;
	posX = in_x;
	id = in_id;
}

bool Projectile::operator==(const Projectile& other) const {
	return this->id == other.id;
}

int Projectile::Update(std::vector<Enemy>& enemies) {
	posY -= SPEED;

	bool hitEnemy = false;
	const int RIGHT = posX + WIDTH;
	const int BOTTOM = posY + HEIGHT;

	for(Enemy& enemy : enemies) {
		const int ENEMY_RIGHT = enemy.GetX() + Enemy::WIDTH;
		const int ENEMY_BOTTOM = enemy.GetY() + Enemy::HEIGHT;

		if(posX <= ENEMY_RIGHT &&
			RIGHT >= enemy.GetX() &&
			posY <= ENEMY_BOTTOM &&
			BOTTOM >= enemy.GetY()) {

			hitEnemy = true;
			enemy.MarkForDeletion();
			Game::IncrementScore();
			break;
		}
	}

	if(posY < 0 || hitEnemy) {
		return 1;
	}
	return 0;
}

void Projectile::Draw(Graphics& gfx) const {
	gfx.DrawRect(posX, posY, WIDTH, HEIGHT, Colors::Red);
}