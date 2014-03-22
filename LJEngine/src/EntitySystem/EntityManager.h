#ifndef ENTITYMANAGER_H__
#define ENTITYMANAGER_H__

#include <vector>
#include <string>

//class GameTime
class Entity;

using namespace std;

class EntityManager
{
public:

	EntityManager();
	~EntityManager();

	
	Entity* createEntity();
	void deleteEntity(string name);
	void deleteEntity(Entity* entity);
	Entity* getEntity(string name);
	std::vector<Entity*> getEntities();

	void fixedUpdate(GameTime* gameTime);
	void update(GameTime* gameTime);
	
	void draw(GameTime* gameTime);

private:

	
	std::vector<Entity*> m_Entities;
	std::vector<int> m_EntitiesToDelete;
	
};


#endif