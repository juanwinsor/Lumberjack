#ifndef COMPONENT_PYRAMID_H_
#define COMPONENT_PYRAMID_H_

#include "Component.h"

class Component_Pyramid : public Component
{
public:
	Component_Pyramid();
	~Component_Pyramid();

	virtual void loadStatic();

	void update(GameTime* gameTime);
	void draw(GameTime* gameTime);
};

#endif

