#include "Player.h"
#include "Colors.h"
#include "Game.h"

void Player::Update(Keyboard& kbd, std::vector<Enemy>& enemies) {
	const float dt = Game::GetDeltaTime();
	fireCooldown += dt;
	if(kbd.KeyIsPressed(VK_SPACE) && fireCooldown >= 0.5f) {
		projectiles.push_back(Projectile(posX + (WIDTH / 2), ELEVATION, nextProjectileID));
		fireCooldown = 0;
		++nextProjectileID;
	}

	const float speed = SPEED * dt;
	const int limit = (int)ceil(speed);
	if(kbd.KeyIsPressed(VK_LEFT) && posX > 0 + limit) {
		posX -= (int)speed;
	}
	if(kbd.KeyIsPressed(VK_RIGHT) && posX + WIDTH < Graphics::ScreenWidth - limit) {
		posX += (int)speed;
	}

	projectiles.erase(std::remove_if(projectiles.begin(), projectiles.end(), [&enemies](Projectile& p) { return p.Update(enemies); }), projectiles.end());
}

void Player::Draw(Graphics& gfx) const {
	gfx.DrawRect(posX, ELEVATION, WIDTH, HEIGHT, Colors::Blue);

	for(const Projectile& p : projectiles) {
		p.Draw(gfx);
	}
}