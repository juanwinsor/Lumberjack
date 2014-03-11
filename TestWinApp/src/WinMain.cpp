//Needed
#include <windows.h>

#include <stdlib.h>

#include <LJEngine\LJEngineTestClass.h>

#include <Box2D/Box2D.h>

class someBoostTest
{

};
BOOST_PTR_DEF(someBoostTest);


/*!
 *
 */
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
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
}