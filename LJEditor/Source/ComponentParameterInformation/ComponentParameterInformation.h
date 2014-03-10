#pragma  once

#include <windows.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;




public ref class ComponentParameterInformation
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

	property int LoadType
	{
		int get ()
		{
			return m_LoadType;
		}
		void set( int value )
		{
			m_LoadType = value;
		}
	}

	property int VarType
	{
		int get ()
		{
			return m_VarType;
		}
		void set( int value )
		{
			m_VarType = value;
		}
	}

private:
	String^ m_Name;
	int m_LoadType;
	int m_VarType;
	String^ m_Discription;
};