#include <iostream>
#include <SDL3/SDL.h>
#include <GameClock.h>

#include "Window.h"
#include "Renderer.h"
#include "Player.h"
#include "Colors.h"
#include "GameConsts.h"

static Window window;
static Renderer renderer;
static float offsetX = (float)window.width / 2;
static float offsetY = (float)window.height / 2;

static constexpr int mapWidth = 15;
static constexpr int mapHeight = 15;
static int map[mapHeight][mapWidth] = {
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 2, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 1,
	1, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

static void drawMap() {
	for (int y = 0; y < sizeof(map) / sizeof(map[0]); y++) {
		for (int x = 0; x < sizeof(map[0]) / sizeof(map[0][0]); x++) {
			if (map[y][x] == 1) {
				drawSquare(renderer, Colors::blue, (float)x * scaledTileSize, (float)y * scaledTileSize, 32, 32);
			}
			else if (map[y][x] == 2) {
				drawSquare(renderer, Colors::red, (float)x * scaledTileSize, (float)y * scaledTileSize, scaledTileSize, scaledTileSize);
			}
			else if (map[y][x] == 3) {
				drawSquare(renderer, Colors::green, (float)x * scaledTileSize, (float)y * scaledTileSize, scaledTileSize, scaledTileSize);
			}
		}
	}
}

static Player player{ (mapWidth * scaledTileSize) / 2, (mapHeight * scaledTileSize) / 2 };

static void draw() {
	clearRenderer(renderer);
	drawMap();
	drawPlayer(renderer, player);
	updatePlayer(window, player, renderer);
	presentRenderer(renderer);
}

static void update() {
	updatePlayer(window, player, renderer);
}

int main() {
	initWindow(window);
	initRenderer(window, renderer);
	GameClock clock;

	bool running = true;

	SDL_Event event;
	while (running) {
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				running = false;
			}
			else if (event.type == SDL_EVENT_WINDOW_RESIZED) {
				resize(window);
				offsetX = (float)window.width / 2;
				offsetY = (float)window.height / 2;
			}
		}

		tick(clock);
		draw();
		rotatePlayer(player);
	}

	destoryWindow(window);
	destoryRenderer(renderer);
	SDL_Quit();
	return 0;
}