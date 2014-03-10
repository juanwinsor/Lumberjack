//Needed
#include <windows.h>

#include <stdlib.h>

#include <LJEngine\LJEngineTestClass.h>

class someBoostTest
{

};
BOOST_PTR_DEF(someBoostTest);


/*!
 *
 */
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	glm::vec2 testVec;
	testVec.x = 0;
	someBoostTestPtr test = someBoostTestPtr(new someBoostTest());

	EngineTestClass::InitEngine();

	EngineTestClass::RenderTriangle();
}