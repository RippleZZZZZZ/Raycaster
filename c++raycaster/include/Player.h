#pragma once
#include "Window.h"
#include "Renderer.h"
#include "MathStuff.h"

struct Player {
	float x = 0;
	float y = 0;
	float angle = 0; // 0 degrees in radians
	float FOV = PI / 3; // 60 degrees in radians

	Player() = default;
	Player(float x, float y) : x(x), y(y) {};
};

void rotatePlayer(Player& player);
void drawPlayer(Renderer& renderer, Player& player);
void updatePlayer(Window& window, Player& player, Renderer& renderer);