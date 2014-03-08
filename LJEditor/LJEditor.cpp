// LJEditor.cpp : main project file.

#include "stdafx.h"
#include "Forms/LumberjackEditor/LumberjackEditor.h"

using namespace LJEditor;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew LumberjackEditor());
	return 0;
}
