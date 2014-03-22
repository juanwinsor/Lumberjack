#ifndef ENTITY_H__
#define ENTITY_H__

#include <string>
#include <map>
#include <vector>

#include "Component.h"
#include "ComponentTypes.h"

class EntityManager;
class GameTime;
class EntityTransform;

using namespace std;

class Entity
{
public:
	Entity();
	~Entity();

	string getName();
	void setName(string name);

	
	//children
	Entity* createChild();

	//components
	Component* getComponent(ComponentType componentType);

	template <typename T> T* addComponent(ComponentType componentType)
	{
		if(m_Components.find(componentType) != m_Components.end())
		{
			//component was found, do nothing

			return NULL;
		}
		else //component doesn't exist
		{
			//create a new component of type T
			Component* component = new T();
			//call its attach
			component->Owner = this;
			component->loadStatic();		
			//insert the component into the component list
			m_Components.insert(pair<ComponentType, Component*>(componentType, component));

			return (T*)component;
		}
	}

	void removeComponent(ComponentType componentType);

	virtual void update(GameTime* gameTime);
	virtual void draw(GameTime* gameTime);

	void setManager(EntityManager* entityManager);
	EntityManager* getManager();
	void setParent(Entity* parent);
	Entity* getParent();

	EntityTransform* getTransform();

protected:	
	EntityManager* m_Manager;
	Entity* m_Parent;

	string m_Name;

	EntityTransform* m_Transform;


	map<ComponentType, Component*>  m_Components;


	
};

#endif