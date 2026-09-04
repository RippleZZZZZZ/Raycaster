#include <GameClock.h>
#include <iostream>
#include <format>

void tick(GameClock& clock) {
	clock.now = SDL_GetPerformanceCounter();
	clock.deltaTime = (float)(clock.now - clock.last) / clock.freq;
	clock.last = clock.now;
}

void getFPS(GameClock& clock) {
	static float tick = 0;
	static int FPS = 0;

	tick += clock.deltaTime;
	FPS++;
	
	if (tick >= 1) {
		tick--;
		std::cout << std::format("FPS: {0}\n", FPS);
		FPS = 0;
	}
}