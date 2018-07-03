/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
float Game::deltatime = 0;
int Game::score = 0;
std::vector<Explosion> Game::explosions;

Game::Game(MainWindow& wnd) : wnd(wnd), gfx(wnd) {
	int y = Y_BORDER;
	int x = X_BORDER;

	for(int i = 0; i < ENEMY_COUNT; ++i) {
		enemies.push_back(new Enemy(x, y));

		x += Enemy::WIDTH + ENEMY_SPACING;
		if(x > Graphics::ScreenWidth - Enemy::WIDTH - X_BORDER) {
			x = X_BORDER;
			y += Enemy::HEIGHT + ENEMY_SPACING;
		}
	}
}

Game::~Game() {
	enemies.erase(enemies.begin(), enemies.end());

	for(int i = 0; i < enemies.size(); ++i) {
		delete enemies[i];
	}
}

void Game::Go() {
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel() {
	player.Update(wnd.kbd, enemies);
	enemies.erase(std::remove_if(enemies.begin(), enemies.end(), [](Enemy* e) {
		if(e->Update()) {
			delete e;
			return true;
		} else {
			return false;
		}
	}), enemies.end());
	explosions.erase(std::remove_if(explosions.begin(), explosions.end(), [](Explosion& e) { return e.Update(); }), explosions.end());
}

float Game::GetDeltaTime() {
	return deltatime;
}

void Game::CreateExplosion(int x, int y, int maximumRadius, int startRadius) {
	explosions.push_back(Explosion(x, y, maximumRadius, startRadius));
}

void Game::IncrementScore() {
	score += 100;
}

void Game::ComposeFrame() {
	deltatime = ft.Mark();
	fpsUpdateCooldown += deltatime;

	player.Draw(gfx);
	for(Enemy* enemy : enemies) {
		enemy->Draw(gfx);
	}
	for(Explosion& e : explosions) {
		e.Draw(gfx);
	}

	if(fpsUpdateCooldown > 0.2f) {
		fps = (int)round(1.0f / deltatime);
		fpsUpdateCooldown = 0.0f;
	}

	gfx.DrawNumber(fps, Graphics::ScreenWidth - (((int)std::to_string(fps).length() + 1) * Graphics::DIGIT_WIDTH) - 5, 5);
	gfx.DrawNumber(score, 5, 5);
}