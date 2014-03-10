#pragma  once

#include <windows.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;




public ref class ComponentInformation
{
public:
	
	property String^ Name
	{
		String^ get() 
		{
			return m_Name;
		}
		void set ( String^ value )
		{
			m_Name = value;
		}
	}

	property String^ Discription
	{
		String^ get() 
		{
			return m_Discription;
		}
		void set( String ^ value )
		{
			m_Discription = value;
		}
	}

	property int BaseClass
	{
		int get ()
		{
			return m_BaseClass;
		}
		void set( int value )
		{
			m_BaseClass = value;
		}
	}

private:
	String^ m_Name;
	String^ m_Discription;
	int m_BaseClass;
};