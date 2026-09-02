#pragma once
#include <SDL3/SDL.h>

struct GameClock {
	size_t last = SDL_GetPerformanceCounter();
	size_t freq = SDL_GetPerformanceFrequency();
	size_t now = 0;
	float deltaTime = 0;
};

void tick(GameClock clock);