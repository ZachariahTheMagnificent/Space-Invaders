#pragma once
#include <vector>
#include "Graphics.h"

class Projectile {
public:
	Projectile(int in_x, int in_y, int in_id);
	bool operator==(const Projectile& other) const;
	int Update();
	void Draw(Graphics& gfx);
private:
	int posX;
	int posY;
	int id;

	static constexpr int speed = 10;
	static constexpr int width = 5;
	static constexpr int height = 20;
};