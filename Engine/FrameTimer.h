#pragma once
#include <chrono>

class FrameTimer {
public:
	FrameTimer();
	float Mark();
	void Reset();
private:
	std::chrono::steady_clock::time_point last;
};