#include "Player.h"
#include "Colors.h"

void Player::Update(Keyboard& kbd) {
	fireCooldown += ft.Mark();
	if(kbd.KeyIsPressed(VK_SPACE) && fireCooldown < 0.7f) {
		projectiles.push_back(Projectile(posX, ELEVATION, nextProjectileID));
		fireCooldown = 0;
		++nextProjectileID;
	}

	if(kbd.KeyIsPressed(VK_LEFT)) {
		posX -= SPEED;
	}
	if(kbd.KeyIsPressed(VK_RIGHT)) {
		posX += SPEED;
	}

	for(Projectile& p : projectiles) {
		if(p.Update()) {
			const auto pos = std::find(projectiles.begin(), projectiles.end(), p);
			projectiles.erase(pos);
		}
	}
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