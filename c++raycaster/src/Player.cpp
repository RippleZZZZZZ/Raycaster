#include "Player.h"
#include <iostream>
#include "Colors.h"
#include "GameConsts.h"

static float rays = 320;
static float cosValue[320];
static float sinValue[320];

void createRayAngles(Player& player) {
	float angleDiff = player.FOV / rays;
	for (int i = 0; i < rays; ++i) {
		float rayAngle = player.angle - (player.FOV / 2) + (i * angleDiff);
		cosValue[i] = cos(rayAngle);
		sinValue[i] = sin(rayAngle);
	}
}

static void castRays(Window& window, Player& player, Renderer& renderer, int map[][15]) {
	float angleX = cos(player.angle);
	float angleY = sin(player.angle);
	for (int i = 0; i < rays; ++i) {
		float dirX = (cosValue[i] * angleX) - (sinValue[i] * angleY);
		float dirY = (cosValue[i] * angleY) + (sinValue[i] * angleX);

		int playerTileX = (int)(player.x / scaledTileSize);
		int playerTileY = (int)(player.y / scaledTileSize);

		int startTileX = playerTileX;
		int startTileY = playerTileY;

		int xStep = 0;
		int yStep = 0;

		if (dirX > 0) {
			xStep = 1;
		}
		else if (dirX < 0) {
			xStep = -1;
		}
		if (dirY > 0) {
			yStep = 1;
		}
		else if (dirY < 0) {
			yStep = -1;
		}

		float deltaX = abs(1 / dirX);
		float deltaY = abs(1 / dirY);

		//bool collision = false;
		//while (!collision) {

		//}

		drawLine(renderer, Colors::white, player.x, player.y, player.x + (dirX * 50), player.y + (dirY * 50));
	}
}

void rotatePlayer(Player& player) {
	player.angle += 0.001f;

	if (player.angle >= 2.0f * PI) {
		player.angle -= 2.0f * PI;
	}
	else if (player.angle <= -2.0f * PI) {
		player.angle += 2.0f * PI;
	}
}

void drawPlayer(Renderer& renderer, Player& player) {
	drawSquare(renderer, Colors::yellow, player.x - (scaledTileSize / 2), player.y - (scaledTileSize / 2), scaledTileSize, scaledTileSize);
	// drawLine(renderer, Colors::orange, player.x, player.y, player.x + (cosf(player.angle) * scaledTileSize), player.y + (sinf(player.angle) * scaledTileSize));
}

void updatePlayer(Window& window, Player& player, Renderer& renderer, int map[][15]) {
	castRays(window, player, renderer, map);
}