#pragma once

#include <windows.h>
#include <gl/Gl.h>
#include <gl/Glu.h>
//#include <LJEngine/LJEngineTestClass.h>
#include <LJEngine/Core.h>
#include <LJengine/Time/GameTime.h>
#include <GLFW/glfw3.h>

using namespace lj;

using namespace System::Windows::Forms;

namespace OpenGLForm 
{
	public ref class COpenGL: public System::Windows::Forms::NativeWindow
	{
	public:

		COpenGL(System::Windows::Forms::Form ^ parentForm, System::Windows::Forms::PictureBox^ pictureBox)
		: m_LastTime (0)
		{

			m_Width = pictureBox->Width;
			m_Height = pictureBox->Height;

			CreateParams^ cp = gcnew CreateParams;

			// Set the position on the form
			cp->X = 0;
			cp->Y = 0;
			cp->Height = pictureBox->Height;
			cp->Width = pictureBox->Width;

			// Specify the form as the parent.
			cp->Parent = pictureBox->Handle; //parentForm->Handle;

			// Create as a child of the specified parent and make OpenGL compliant (no clipping)
			cp->Style = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

			// Create the actual window
			this->CreateHandle(cp);

			m_hDC = GetDC((HWND)this->Handle.ToPointer());

			if(m_hDC)
			{
				MySetPixelFormat(m_hDC);				
				InitGL();
				ReSizeGLScene(pictureBox->Width, pictureBox->Height);
			}

			rtri = 0.0f;
			rquad = 0.0f;

		}

		

		System::Void Render(System::Void)
		{
			float t = glfwGetTime();
			m_GameTime->deltaTime = t - m_LastTime;
			m_GameTime->totalTime += m_GameTime->deltaTime;
			m_LastTime = t;

			m_Core->preDraw();
			m_Core->draw( m_GameTime );
		}

		System::Void SwapOpenGLBuffers(System::Void)
		{
			SwapBuffers(m_hDC) ;
		}

		System::Void UpdateGLSceneSize( int x, int y )
		{
			ReSizeGLScene(x, y);
		}

		HDC getWindowHandle()
		{
			return m_hDC;
		}

		HGLRC getGLContextHandler()
		{
			return m_hglrc;
		}

	private:
		HDC m_hDC;
		HGLRC m_hglrc;
		GLfloat	rtri;				// Angle for the triangle
		GLfloat	rquad;				// Angle for the quad

		int m_Width;
		int m_Height;

		Core* m_Core;
		GameTime* m_GameTime;
		float m_LastTime;

	protected:
		~COpenGL(System::Void)
		{
			this->DestroyHandle();
		}

		GLint MySetPixelFormat(HDC hdc)
		{
			static	PIXELFORMATDESCRIPTOR pfd=				// pfd Tells Windows How We Want Things To Be
				{
					sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
					1,											// Version Number
					PFD_DRAW_TO_WINDOW |						// Format Must Support Window
					PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
					PFD_DOUBLEBUFFER,							// Must Support Double Buffering
					PFD_TYPE_RGBA,								// Request An RGBA Format
					16,										// Select Our Color Depth
					0, 0, 0, 0, 0, 0,							// Color Bits Ignored
					0,											// No Alpha Buffer
					0,											// Shift Bit Ignored
					0,											// No Accumulation Buffer
					0, 0, 0, 0,									// Accumulation Bits Ignored
					16,											// 16Bit Z-Buffer (Depth Buffer)  
					0,											// No Stencil Buffer
					0,											// No Auxiliary Buffer
					PFD_MAIN_PLANE,								// Main Drawing Layer
					0,											// Reserved
					0, 0, 0										// Layer Masks Ignored
				};
			
			GLint  iPixelFormat; 
		 
			// get the device context's best, available pixel format match 
			if((iPixelFormat = ChoosePixelFormat(hdc, &pfd)) == 0)
			{
				MessageBox::Show("ChoosePixelFormat Failed");
				return 0;
			}
			 
			// make that match the device context's current pixel format 
			if(SetPixelFormat(hdc, iPixelFormat, &pfd) == FALSE)
			{
				MessageBox::Show("SetPixelFormat Failed");
				return 0;
			}

			if((m_hglrc = wglCreateContext(m_hDC)) == NULL)
			{
				MessageBox::Show("wglCreateContext Failed");
				return 0;
			}

			if((wglMakeCurrent(m_hDC, m_hglrc)) == NULL)
			{
				MessageBox::Show("wglMakeCurrent Failed");
				return 0;
			}


			return 1;
		}

		bool InitGL(GLvoid)										// All setup for opengl goes here
		{
			glShadeModel(GL_SMOOTH);							// Enable smooth shading
			glClearColor(0.39f, 0.584f, 0.9294f, 1.0f);				// Black background
			glClearDepth(1.0f);									// Depth buffer setup
			glEnable(GL_DEPTH_TEST);							// Enables depth testing
			glDepthFunc(GL_LEQUAL);								// The type of depth testing to do
			glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really nice perspective calculations			
			
			m_Core = new Core();
			m_Core->initialize();
			m_GameTime = new GameTime;
			
			m_LastTime = glfwGetTime();

			return TRUE;										// Initialisation went ok
		}

		GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize and initialise the gl window
		{
			if (height==0)										// Prevent A Divide By Zero By
			{
				height=1;										// Making Height Equal One
			}

			glViewport(0,0,width,height);						// Reset The Current Viewport

			glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
			glLoadIdentity();									// Reset The Projection Matrix

			// Calculate The Aspect Ratio Of The Window
			gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
			//glOrtho(-(GLfloat)width/(GLfloat)height, (GLfloat)width/(GLfloat)height, -1.f, 1.f, 1.f, -1.f);
			

			glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
			glLoadIdentity();									// Reset The Modelview Matrix

		}
	};
}