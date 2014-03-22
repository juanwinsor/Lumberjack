#include <Windows.h>
#include <GLFW/glfw3.h>

#include "EntitySystem/Entity.h"
#include "EntitySystem/EntityManager.h"
#include "EntitySystem/Component_Pyramid.h"

#include "Core.h"


using namespace lj;

Core::Core()
{

}

Core::~Core()
{

}

void Core::initialize()
{
	glfwInit();


	m_EntityManager = new EntityManager();
	Entity* test = m_EntityManager->createEntity();
	Component_Pyramid* pyramid = test->addComponent<Component_Pyramid>(COMPONENT_PYRAMID);
}

void Core::fixedUpdate(GameTime* gameTime)
{

}

void Core::update(GameTime* gameTime)
{
	m_EntityManager->update( gameTime );
}

void Core::lateUpdate(GameTime* gameTime)
{

}

void Core::preDraw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear screen and depth buffer
}

void Core::draw(GameTime* gameTime)
{
	m_EntityManager->draw( gameTime );
}