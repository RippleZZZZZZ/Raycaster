#pragma once
#include <SDL3/SDL.h>

struct Window { 
	SDL_Window* window = nullptr;
	int width = 640;
	int height = 480;
	bool fullscreen = false;
};

void initWindow(Window& window);
void resize(Window& window);
void destoryWindow(Window& window);