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

void Core::draw(GameTime* gameTime)
{
	glLoadIdentity();         // Reset the current modelview matrix
	glTranslatef(-1.5f,0.0f,-6.0f);      // Move left 1.5 units and into the screen 6.0
	glRotatef(gameTime->totalTime * 50.0f,0.0f,1.0f,0.0f);      // Rotate the triangle on the y axis 
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