#ifndef COMPONENT_H__
#define COMPONENT_H__

class GameTime;
class Entity;

class Component
{
public:
	Component();
	~Component();

	void setActive(bool active);
	bool isActive();

	void baseUpdate(GameTime* gameTime);

	virtual void loadStatic();
	virtual void loadState();
	virtual void update(GameTime* gameTime) = 0;
	virtual void draw(GameTime* gameTime){}
	virtual void unload();

	Entity* Owner;
protected:

	bool m_Active;
};

#endif