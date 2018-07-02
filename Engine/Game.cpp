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

Game::Game(MainWindow& wnd): wnd(wnd), gfx(wnd) {
	int y = ENEMY_Y_BORDER;
	int x = ENEMY_X_BORDER;
	int row = 1;
	int column = 1;

	for(int enemyNumber = 0; enemyNumber < ENEMY_COUNT; ++enemyNumber) {
		enemies.push_back(Enemy(x, y));

		x = column++ * Enemy::WIDTH + ENEMY_SPACING;

		if(x > Graphics::ScreenWidth - Enemy::WIDTH - ENEMY_X_BORDER) {
			x = ENEMY_X_BORDER;
			y = row++ * Enemy::HEIGHT + ENEMY_SPACING;
		}
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
	for(Enemy& enemy : enemies) {
		enemy.Update();
	}
}

void Game::ComposeFrame() {
	player.Draw(gfx);
	for(Enemy& enemy : enemies) {
		enemy.Draw(gfx);
	}
}
