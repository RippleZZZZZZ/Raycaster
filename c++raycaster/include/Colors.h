#pragma once
#include <SDL3/SDL.h>

namespace Colors {
	inline constexpr SDL_Color red = { 255, 0, 0, 255 };
	inline constexpr SDL_Color blue = { 0, 0, 255, 255 };
	inline constexpr SDL_Color green = { 0, 255, 0, 255 };
	inline constexpr SDL_Color yellow = { 255, 255, 0, 255 };
	inline constexpr SDL_Color orange = { 255, 140, 0, 255 };
	inline constexpr SDL_Color white = { 255, 255, 255, 255 };
}