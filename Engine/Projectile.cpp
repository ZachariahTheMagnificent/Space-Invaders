#include "Projectile.h"

Projectile::Projectile(int in_x, int in_y, int in_id) {
	posY = in_y;
	posX = in_x;
	id = in_id;
}

bool Projectile::operator==(const Projectile& other) const {
	return this->id == other.id;
}

int Projectile::Update() {
	posY -= speed;

	if(posY < 0) {
		return 1;
	}
	return 0;
}

void Projectile::Draw(Graphics& gfx) {
	for(int y = posY; y < posY + height; ++y) {
		for(int x = posX; x < posX + width; ++x) {
			gfx.PutPixel(x, y, Colors::Red);
		}
	}
}