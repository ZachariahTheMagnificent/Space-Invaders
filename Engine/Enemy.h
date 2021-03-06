#pragma once
#include "Graphics.h"

class Enemy {
public:
	Enemy(const int in_x, const int in_y);

	void Draw(Graphics& gfx) const;

	void Move();
	void Update();

	void MarkForDeletion();
	bool IsDead() const;
	void OnDestroy();

	int GetX() const;
	int GetY() const;

	static constexpr int WIDTH = 30;
	static constexpr int HEIGHT = 25;
private:
	int posX, posY;
	bool toBeDeleted = false;

	static float horSpeed;
	static float vertSpeed;
};