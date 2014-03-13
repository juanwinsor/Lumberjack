#include <Windows.h>
#include <GLFW/glfw3.h>

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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear screen and depth buffer
}

void Core::setWindowSize(int width, int height)
{
	m_Width = width;
	m_Height = height;
}

void Core::drawNative(GameTime* gameTime)
{
	float ratio;

	//Get the width and size of the framebuffer
	//glfwGetFramebufferSize(m_Window, &width, &height);
	//Calculate the aspect ratio
	ratio = m_Width / (float) m_Height;

	//Set the viewport size we want
	glViewport(0, 0, m_Width, m_Height);

	//Clear the color every frame
	glClearColor(1.0f, 0, 0, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	//Clear();

	//Set up the projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);

	//Set up the world matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(gameTime->deltaTime * 50.f, 0.f, 0.f, 1.f);

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
	//glfwSwapBuffers(m_Window);
	//SwapBuffers((HDC)m_WindowHandle);
}

void Core::draw(GameTime* gameTime)
{
	glLoadIdentity();         // Reset the current modelview matrix
	glTranslatef(-1.5f,0.0f,-6.0f);      // Move left 1.5 units and into the screen 6.0
	glRotatef(gameTime->totalTime,0.0f,1.0f,0.0f);      // Rotate the triangle on the y axis 
	glBegin(GL_TRIANGLES);        // Start drawing a triangle
	glColor3f(1.0f,0.0f,0.0f);      // Red
	glVertex3f( 0.0f, 1.0f, 0.0f);     // Top Of triangle (front)
	glColor3f(0.0f,1.0f,0.0f);      // Green
	glVertex3f(-1.0f,-1.0f, 1.0f);     // Left of triangle (front)
	glColor3f(0.0f,0.0f,1.0f);      // Blue
	glVertex3f( 1.0f,-1.0f, 1.0f);     // Right of triangle (front)
	glColor3f(1.0f,0.0f,0.0f);      // Red
	glVertex3f( 0.0f, 1.0f, 0.0f);     // Top Of triangle (right)
	glColor3f(0.0f,0.0f,1.0f);      // Blue
	glVertex3f( 1.0f,-1.0f, 1.0f);     // Left of triangle (right)
	glColor3f(0.0f,1.0f,0.0f);      // Green
	glVertex3f( 1.0f,-1.0f, -1.0f);     // Right of triangle (right)
	glColor3f(1.0f,0.0f,0.0f);      // Red
	glVertex3f( 0.0f, 1.0f, 0.0f);     // Top Of triangle (back)
	glColor3f(0.0f,1.0f,0.0f);      // Green
	glVertex3f( 1.0f,-1.0f, -1.0f);     // Left of triangle (back)
	glColor3f(0.0f,0.0f,1.0f);      // Blue
	glVertex3f(-1.0f,-1.0f, -1.0f);     // Right of triangle (back)
	glColor3f(1.0f,0.0f,0.0f);      // Red
	glVertex3f( 0.0f, 1.0f, 0.0f);     // Top Of triangle (left)
	glColor3f(0.0f,0.0f,1.0f);      // Blue
	glVertex3f(-1.0f,-1.0f,-1.0f);     // Left of triangle (left)
	glColor3f(0.0f,1.0f,0.0f);      // Green
	glVertex3f(-1.0f,-1.0f, 1.0f);     // Right of triangle (left)
	glEnd();
}