//Needed
#include <windows.h>
#include <stdlib.h>

//#include <LJEngine\LJEngineTestClass.h>
//#include <Box2D/Box2D.h>

#include <gl/GLU.h>
#include <GLFW/glfw3.h>
#include <LJEngine/Core.h>
#include <LJEngine/Time/GameTime.h>

using namespace lj;

Core __core;


class someBoostTest
{

};
BOOST_PTR_DEF(someBoostTest);


void initGL()
{
	glShadeModel(GL_SMOOTH);							// Enable smooth shading
	glClearColor(0.39f, 0.584f, 0.9294f, 1.0f);				// Black background
	glClearDepth(1.0f);									// Depth buffer setup
	glEnable(GL_DEPTH_TEST);							// Enables depth testing
	glDepthFunc(GL_LEQUAL);								// The type of depth testing to do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really nice perspective calculations
}

void resizeGL(GLFWwindow* window)
{
	float ratio;
	int width, height;

	//Get the width and size of the framebuffer
	glfwGetFramebufferSize(window, &width, &height);
	//Calculate the aspect ratio
	ratio = width / (float) height;

	glViewport(0,0,width,height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix
	//glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
	//glFrustum(-ratio, ratio, -1.0, 1.0, 0.1f, 100);
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}


/*!
 *
 */
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	/*
	//-- test box2d
	//b2Vec2 gravity(0, -1.0f);
	//b2World world(gravity);

	//-- test glm
	glm::vec2 testVec;
	testVec.x = 0;

	//-- test boost
	someBoostTestPtr test = someBoostTestPtr(new someBoostTest());

	EngineTestClass::InitEngine();

	EngineTestClass::RenderTriangle();
	*/

	


	//-- setup engine	
	__core.initialize();


	//Reference to the window we will make
	GLFWwindow* window;
	//Create the window with whatever parameters we want
	window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);

	//If the window didn't get created properly, terminate
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//TEST: Setting the title just to see if this shit works
	glfwSetWindowTitle(window, "TEST TITLE");

	//Make the new window the focus
	glfwMakeContextCurrent(window);

	//-- initialize GL states
	initGL();

	resizeGL(window);

	//-- game time
	GameTime* gameTime = new GameTime();
	l_f32 lastTime = glfwGetTime();

	l_f32 fixedTimeAccumulator = 0;

	//While the window is valid
	while (!glfwWindowShouldClose(window))
	{
		//-- calculate time
		l_f32 t = glfwGetTime();
		l_f32 delta = ( t - lastTime );
		lastTime = t;
		//-- prevent spiral of death
		if( delta > 0.25f )
		{
			delta = 0.25f;
		}
		//-- cache delta and total time
		gameTime->deltaTime = delta;
		gameTime->totalTime += delta;

		//-- process fixed time step
		fixedTimeAccumulator += delta;
		while( fixedTimeAccumulator > gameTime->fixedStep )
		{
			__core.fixedUpdate( gameTime );

			fixedTimeAccumulator -= gameTime->fixedStep;
		}
		l_f32 alpha = fixedTimeAccumulator / gameTime->fixedStep;
		//-- cache the alpha value
		gameTime->alpha = alpha;


		//-- update
		__core.update( gameTime );

		__core.lateUpdate( gameTime );

		//-- draw
		__core.preDraw();

		__core.draw( gameTime );

		glfwSwapBuffers(window);
		
		//Poll for any events
		glfwPollEvents();
	}

	//Destroy the window now
	glfwDestroyWindow(window);


	//-- cleanup engine
	delete gameTime;

	//GLFW isn't needed, terminate it
	glfwTerminate();
	exit(EXIT_SUCCESS);


}