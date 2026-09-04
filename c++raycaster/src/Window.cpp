#include <Window.h>
#include <iostream>
#include <format>

void initWindow(Window& window) {
	window.window = SDL_CreateWindow("raycaster", window.width, window.height, SDL_WINDOW_HIGH_PIXEL_DENSITY | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALWAYS_ON_TOP);

	if (!window.window) {
		std::cout << "failed to init window!\n";
		SDL_Quit();
	}
}

void resize(Window& window) {
	SDL_GetWindowSizeInPixels(window.window, &window.width, &window.height);
	std::cout << std::format("Window Size: {0}, {1}\n", window.width, window.height);
}



void destoryWindow(Window& window) {
	SDL_DestroyWindow(window.window);
}