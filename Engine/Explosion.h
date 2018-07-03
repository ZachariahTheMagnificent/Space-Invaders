#pragma once
#include "Graphics.h"
#include <random>

class Explosion {
public:
	Explosion(int in_x, int in_y, int maximumRadius, int startRadius);
	bool Update(Graphics& gfx);
private:
	Color color = {255, 0, 0};
	float updateCooldown = 0.0f;

	int maxRadius;
	int radius;

	int x, y;

	std::uniform_int_distribution<int> redDist;
	std::uniform_int_distribution<int> greenDist;
	std::uniform_int_distribution<int> blueDist;
};