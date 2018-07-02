#include "Player.h"
#include "Colors.h"

void Player::Update(Keyboard& kbd) {
	fireCooldown += ft.Mark();
	if(kbd.KeyIsPressed(VK_SPACE) && fireCooldown >= 0.4f) {
		projectiles.push_back(Projectile(posX + (WIDTH / 2), ELEVATION, nextProjectileID));
		fireCooldown = 0;
		++nextProjectileID;
	}

	if(kbd.KeyIsPressed(VK_LEFT)) {
		posX -= SPEED;
	}
	if(kbd.KeyIsPressed(VK_RIGHT)) {
		posX += SPEED;
	}

	projectiles.erase(std::remove_if(projectiles.begin(), projectiles.end(), [](Projectile& p) { return p.Update(); }), projectiles.end());
}

void Player::Draw(Graphics& gfx) {
	for(int y = ELEVATION; y < ELEVATION + HEIGHT; ++y) {
		for(int x = posX; x < posX + WIDTH; ++x) {
			gfx.PutPixel(x, y, Colors::Blue);
		}
	}

	for(Projectile& p : projectiles) {
		p.Draw(gfx);
	}
}