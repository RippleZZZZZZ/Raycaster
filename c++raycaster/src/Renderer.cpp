#include <Renderer.h>
#include <iostream>

void initRenderer(Window& window, Renderer& renderer) {
	renderer.renderer = SDL_CreateRenderer(window.window, nullptr);

	if (!renderer.renderer) {
		std::cout << "failed to init renderer!\n";
		destoryWindow(window);
		SDL_Quit();
	}
}

void drawSquare(Renderer& renderer, SDL_Color color, float x, float y, float width, float height) {
	SDL_FRect rect = { x, y, width, height };

	SDL_SetRenderDrawColor(renderer.renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(renderer.renderer, &rect);
}

void drawLine(Renderer& renderer, SDL_Color color, float x1, float y1, float x2, float y2) {
	SDL_SetRenderDrawColor(renderer.renderer, color.r, color.g, color.b, color.a);
	SDL_RenderLine(renderer.renderer, x1, y1, x2, y2);
}

void clearRenderer(Renderer& renderer) {
	SDL_SetRenderDrawColor(renderer.renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer.renderer);
}

void presentRenderer(Renderer& renderer) {
	SDL_RenderPresent(renderer.renderer);
}

void destoryRenderer(Renderer& renderer) {
	SDL_DestroyRenderer(renderer.renderer);
}