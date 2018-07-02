#include "FrameTimer.h"
using namespace std::chrono;

FrameTimer::FrameTimer() {
	Reset();
}

float FrameTimer::Mark() {
	auto old = last;
	Reset();
	const duration<float> frametime = last - old;
	return frametime.count();
}

void FrameTimer::Reset() {
	last = steady_clock::now();
}
