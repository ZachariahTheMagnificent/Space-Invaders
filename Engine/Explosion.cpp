#include "Explosion.h"
#include "Game.h"

Explosion::Explosion(int in_x, int in_y, int maximumRadius, int startRadius): redDist(220, 255), greenDist(0, 20), blueDist(50, 255) {
	x = in_x;
	y = in_y;
	maxRadius = maximumRadius;
	radius = startRadius;
}

bool Explosion::Update() {
	updateCooldown += Game::GetDeltaTime();

	if(radius < maxRadius) {
		if(updateCooldown > 0.2f){
			++radius;
			std::mt19937 rng(time(0));

			const unsigned char red = redDist(rng);
			const unsigned char green = greenDist(rng);
			const unsigned char blue = blueDist(rng);

			color = {red, green, blue};
			updateCooldown = 0.0f;
		}
	} else {
		return true;
	}
	return false;
}

void Explosion::Draw(Graphics& gfx) {
	gfx.DrawCircle(x, y, radius, color);
}