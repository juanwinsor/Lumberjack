#ifndef LJGAMETIME_H_
#define LJGAMETIME_H_

namespace lj
{
	struct GameTime
	{
		GameTime()
		{
			deltaTime = 0;
			totalTime = 0;
			fixedStep = 1.0f / 60.0f;
			alpha = 0;
		}

		float deltaTime;
		float totalTime;
		float fixedStep;
		float alpha;
	};
}

#endif