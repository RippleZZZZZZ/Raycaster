#pragma once
#include <SDL3/SDL.h>
#include <Window.h>

struct Renderer { 
	SDL_Renderer* renderer = nullptr;
};

void initRenderer(Window& window, Renderer& renderer);
void clearRenderer(Renderer& renderer);
void drawSquare(Renderer& renderer, SDL_Color color, float x, float y, float width, float height);
void drawLine(Renderer& renderer, SDL_Color, float x1, float y1, float x2, float y2);
void presentRenderer(Renderer& renderer);
void destoryRenderer(Renderer& renderer);