#pragma  once

#include <windows.h>
#include "../ComponentParameterInformation/ComponentParameterInformation.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;

using namespace System::Collections::Generic;


public ref class ComponentInformation
{
public:
	ComponentInformation()
	{
		m_ComponentParameters = gcnew List<ComponentParameterInformation^>();
	}
	
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

	property String^ BaseClassName
	{
		String^  get ()
		{
			return m_BaseName;
		}
		void set( String^  value )
		{
			m_BaseName = value;
		}
	}

	property List<ComponentParameterInformation^>^ ComponentParameters
	{
		List<ComponentParameterInformation^>^ get ()
		{
			return m_ComponentParameters;
		}
		void set( List<ComponentParameterInformation^>^ value )
		{
			m_ComponentParameters = value;
		}
	}

private:
	String^ m_Name;
	String^ m_Discription;
	String^ m_BaseName;

	System::Collections::Generic::List<ComponentParameterInformation^>^ m_ComponentParameters ;
};