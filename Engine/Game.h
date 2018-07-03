/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Player.h"
#include "Enemy.h"
#include "FrameTimer.h"

class Game {
public:
	Game(class MainWindow& wnd);
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
public:
	static float GetDeltaTime();
	static void IncrementScore();
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	FrameTimer ft;
	static float deltatime;
	float fpsUpdateCooldown = 0.0f;
	int fps = 0;

	Player player;
	std::vector<Enemy> enemies;

	static int score;

	static constexpr int ENEMY_COUNT = 39;
	static constexpr int X_BORDER = 35;
	static constexpr int Y_BORDER = 46;
	static constexpr int ENEMY_SPACING = 6;

	static constexpr int SCORE_OFFSET = 10;
	/********************************/
};