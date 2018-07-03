#include "Player.h"
#include "Colors.h"
#include "Game.h"

void Player::Update(Keyboard& kbd, std::vector<Enemy>& enemies) {
	fireCooldown += Game::GetDeltaTime();
	if(kbd.KeyIsPressed(VK_SPACE) && fireCooldown >= 0.4f) {
		projectiles.push_back(Projectile(posX + (WIDTH / 2), ELEVATION, nextProjectileID));
		fireCooldown = 0;
		++nextProjectileID;
	}

	if(kbd.KeyIsPressed(VK_LEFT) && posX > 0 + SPEED) {
		posX -= SPEED;
	}
	if(kbd.KeyIsPressed(VK_RIGHT) && posX + WIDTH < Graphics::ScreenWidth - SPEED) {
		posX += SPEED;
	}

	projectiles.erase(std::remove_if(projectiles.begin(), projectiles.end(), [&enemies](Projectile& p) { return p.Update(enemies); }), projectiles.end());
}

void Player::Draw(Graphics& gfx) const {
	gfx.DrawRect(posX, ELEVATION, WIDTH, HEIGHT, Colors::Blue);

	for(const Projectile& p : projectiles) {
		p.Draw(gfx);
	}
}