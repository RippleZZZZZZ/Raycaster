#include "Player.h"
#include <iostream>
#include "Colors.h"
#include "GameConsts.h"

void castRays(Window& window, Player& player, Renderer& renderer) {
	float rays = (float)window.width / 2;
	float angleDiff = player.FOV / rays;
	for (int i = 0; i < rays; i++) {
		float rayAngle = player.angle - (player.FOV / 2) + (i * angleDiff);
		drawLine(renderer, Colors::orange, player.x, player.y, player.x + (cosf(rayAngle) * scaledTileSize), player.y + (sinf(rayAngle) * scaledTileSize));
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
	// drawLine(renderer, Colors::orange, player.x, player.y, player.x + (cosf(player.angle * PI) * scaledTileSize), player.y + (sinf(player.angle * PI) * scaledTileSize));
}

void updatePlayer(Window& window, Player& player, Renderer& renderer) {
	castRays(window, player, renderer);
}