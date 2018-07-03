#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "FrameTimer.h"
#include "Projectile.h"
#include <vector>

class Player {
public:
	void Update(Keyboard& kbd, std::vector<Enemy>& enemies);
	void Draw(Graphics& gfx) const;
	static constexpr int ELEVATION = Graphics::ScreenHeight - 50;
private:
	std::vector<Projectile> projectiles;

	static constexpr float SPEED = 160.0f;
	static constexpr int WIDTH = 50;
	static constexpr int HEIGHT = 25;

	int posX = Graphics::ScreenWidth / 2 - WIDTH;
	float fireCooldown = 0;
	int nextProjectileID = 0;
};