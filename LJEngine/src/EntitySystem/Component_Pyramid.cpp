#include <GLFW/glfw3.h>
#include "Component_Pyramid.h"
#include "EntityTransform.h"
#include "Entity.h"

Component_Pyramid::Component_Pyramid()
{
}


Component_Pyramid::~Component_Pyramid()
{
}

void Component_Pyramid::loadStatic()
{
	
}


void Component_Pyramid::update(GameTime* gameTime)
{
	float x = glm::sin(gameTime->totalTime);

	Owner->getTransform()->setPosition( glm::vec3(x, 0, 0) );
}

void Component_Pyramid::draw(GameTime* gameTime)
{
	glLoadIdentity();         // Reset the current modelview matrix

	EntityTransform* t = Owner->getTransform();
	mat4 w = t->getWorldMatrix();
	glMultMatrixf( &w[0][0] );

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
