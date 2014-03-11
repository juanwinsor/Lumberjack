#include <GLFW/glfw3.h>

#include "Core.h"

using namespace lj;

Core::Core()
{

}

Core::~Core()
{

}

void Core::initialize(GLFWwindow* window)
{
	m_Window = window;
}

void Core::fixedUpdate(GameTime* gameTime)
{

}

void Core::update(GameTime* gameTime)
{

}

void Core::lateUpdate(GameTime* gameTime)
{

}

void Core::preDraw()
{

}

void Core::draw(GameTime* gameTime)
{
	float ratio;
	int width, height;

	//Get the width and size of the framebuffer
	glfwGetFramebufferSize(m_Window, &width, &height);
	//Calculate the aspect ratio
	ratio = width / (float) height;

	//Set the viewport size we want
	glViewport(0, 0, width, height);

	//Clear the color every frame
	glClear(GL_COLOR_BUFFER_BIT);
	//Clear();

	//Set up the projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);

	//Set up the world matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);

	//Render the spining triangle
	glBegin(GL_TRIANGLES);
	glColor3f(1.f, 0.f, 0.f);
	glVertex3f(-0.6f, -0.4f, 0.f);
	glColor3f(0.f, 1.f, 0.f);
	glVertex3f(0.6f, -0.4f, 0.f);
	glColor3f(0.f, 0.f, 1.f);
	glVertex3f(0.f, 0.6f, 0.f);
	glEnd();

	//Swap the buffers
	glfwSwapBuffers(m_Window);
}