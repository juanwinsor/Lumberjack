#ifndef LJGAMETIME_H_
#define LJGAMETIME_H_

class GameTime
{
public:
	GameTime();

	float deltaTime;
	float totalTime;
	float fixedStep;
	float alpha;
};


#endif