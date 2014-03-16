#include <string>


#include "EntityManager.h"
#include "ComponentTypes.h"
#include "Component.h"
#include "EntityTransform.h"

#include "Entity.h"

using namespace std;

Entity::Entity()
{
	
	m_Parent = NULL;
	m_Transform = new EntityTransform( this );
	
}

Entity::~Entity()
{
	
	map<ComponentType, Component*>::iterator it;

	for(it = m_Components.begin(); it != m_Components.end(); it++)
	{
		m_Components.at(it->first)->unload();
		//delete the component
		delete m_Components.at(it->first);
		//break;
	}

	m_Components.clear();


	delete m_Transform;
	
}


string Entity::getName()
{
	return m_Name;
}

void Entity::setName(string name)
{
	m_Name = name;
}

Component* Entity::getComponent(ComponentType componentType)
{
	//std::string testString = this->Name();
	map<ComponentType, Component*>::iterator it = m_Components.find(componentType);



	if(it != m_Components.end())
	{
		return it->second;
	}
}

void Entity::removeComponent(ComponentType componentType)
{
	map<ComponentType, Component*>::iterator it;
	for(it = m_Components.begin(); it != m_Components.end(); it++)
	{
		if(it->first == componentType)
		{
			break;
		}
	}

	if(it->first != NULL)
	{
		it->second->unload();
		m_Components.erase(it);
	}
}

void Entity::update(GameTime* gameTime)
{
	map<ComponentType, Component*>::iterator it;

	for(it = m_Components.begin(); it != m_Components.end(); it++)
	{
		it->second->baseUpdate(gameTime);
	}
}

void Entity::draw(GameTime* gameTime)
{
	map<ComponentType, Component*>::iterator it;

	for(it = m_Components.begin(); it != m_Components.end(); it++)
	{
		it->second->draw(gameTime);
	}
}

Entity* Entity::createChild()
{
	//create the entity with the entity manager
	Entity* entity = m_Manager->createEntity();
	//pass a reference to the entitymanager
	entity->setManager(m_Manager);
	//set the parent of this child to this instance
	entity->setParent(this);

	return entity;
}

void Entity::setManager(EntityManager* entityManager)
{
	m_Manager = entityManager;
}

void Entity::setParent(Entity* parent)
{
	m_Parent = parent;
}

Entity* Entity::getParent()
{
	return m_Parent;
}

EntityManager* Entity::getManager()
{
	return m_Manager;
}

EntityTransform* Entity::getTransform()
{
	return m_Transform;
}
