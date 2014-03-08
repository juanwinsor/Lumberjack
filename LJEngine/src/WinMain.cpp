//Needed
#include <windows.h>

#include <stdlib.h>

//Temp
#include <GLFW\glfw3.h>
#include <TestLib\GLFWTest.h>

//test class
class testClass
{
public:
	testClass()
		:testMember(42){}

	int testMember;
};
BOOST_PTR_DEF(testClass);


/*!
 *
 */
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//Initializing GLFW.  Must be done before any glfw calls can be made
	glfwInit();

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

	GLFWTest::clearToCornflowerBlue();



	//-- testing shared pointer macro
	testClassPtr myClass = testClassPtr( new testClass() );
	char* someValue = new char[256];
	sprintf(someValue, "\n\nValue of myClass->testMember : %d\n\n", myClass->testMember);
	OutputDebugStringA(someValue);

	//-- testing glm
	glm::vec4 color(1.0f, 0, 0, 1.0f);
	sprintf(someValue, "\n\nValue of color : [%f, %f, %f, %f]\n\n", color.r, color.g, color.b, color.a);
	OutputDebugStringA(someValue);

	glm::mat4 test = glm::ortho<float>(0, 0, 100.0f, 100.0f);

	//While the window is valid
	while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;

		//Get the width and size of the framebuffer
        glfwGetFramebufferSize(window, &width, &height);
		//Calculate the aspect ratio
        ratio = width / (float) height;

		//Set the viewport size we want
        glViewport(0, 0, width, height);

		//Clear the color every frame
        glClear(GL_COLOR_BUFFER_BIT);

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
        glfwSwapBuffers(window);
		//Poll for any events
        glfwPollEvents();
    }

	//Destroy the window now
    glfwDestroyWindow(window);

	//GLFW isn't needed, terminate it
    glfwTerminate();
    exit(EXIT_SUCCESS);
}