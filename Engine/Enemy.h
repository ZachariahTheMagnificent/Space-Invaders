#pragma once
#include "Graphics.h"
class Enemy {
public:
	Enemy(const int in_x, const int in_y);
	void Draw(Graphics& gfx) const;
	void Update();
	int GetX() const;
	int GetY() const;

	static constexpr int WIDTH = 50;
	static constexpr int HEIGHT = 25;
private:
	int posX, posY;

	static constexpr int SPEED = 3;
};