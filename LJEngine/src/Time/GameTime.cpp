#include "GameTime.h"


GameTime::GameTime()
{
	deltaTime = 0;
	totalTime = 0;
	fixedStep = 1.0f / 60.0f;
	alpha = 0;
}