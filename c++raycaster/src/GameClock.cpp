#include <GameClock.h>

void tick(GameClock clock) {
	clock.now = SDL_GetPerformanceCounter();
	clock.deltaTime = (float)(clock.now - clock.last) / clock.freq;
	clock.last = clock.now;
}