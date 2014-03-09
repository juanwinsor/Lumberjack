//Needed
#include <windows.h>

#include <stdlib.h>

#include <LJEngine\LJEngineTestClass.h>


/*!
 *
 */
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	EngineTestClass::InitEngine();

	EngineTestClass::RenderTriangle();
}