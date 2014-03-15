#include "../Time/GameTime.h"

#include "Component.h"


Component::Component()
:m_Active(true)
{

}

Component::~Component()
{

}

void Component::setActive(bool active)
{
	m_Active = active;
}

bool Component::isActive()
{
	return m_Active;
}

void Component::loadStatic()
{

}

void Component::loadState()
{

}

void Component::unload()
{

}

void Component::baseUpdate(GameTime* gameTime)
{
	//-- update the component if it is active
	if( m_Active == true )
	{
		update( gameTime );
	}
}