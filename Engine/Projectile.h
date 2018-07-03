#pragma once
#include <vector>
#include "Graphics.h"
#include "Enemy.h"

class Projectile {
public:
	Projectile(int in_x, int in_y, int in_id);
	bool operator==(const Projectile& other) const;
	int Update(std::vector<Enemy>& enemies);
	void Draw(Graphics& gfx) const;
private:
	int posX;
	int posY;
	int id;

	static constexpr int SPEED = 10;
	static constexpr int WIDTH = 7;
	static constexpr int HEIGHT = 25;
};