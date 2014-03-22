#pragma once

#include "../../Controls/CFileBrowser.h"
#include "../../Source/ComponentInformation/ComponentInformation.h"

namespace Util
{
	class EnumUtils
	{
	public:
		static List<String^>^ getVariableTypes()
		{
			List<String^>^ VariableTypes = gcnew List<String^>();
			VariableTypes->Add(" f32 ");
			VariableTypes->Add(" f64 ");
			VariableTypes->Add(" s32 ");
			VariableTypes->Add(" str ");
			VariableTypes->Add(" bool ");
			return VariableTypes;
		}

		static List<String^>^ getLoadTypes()
		{
			List<String^>^ LoadTypes = gcnew List<String^>();
			LoadTypes->Add(" static ");
			LoadTypes->Add(" state ");
			return LoadTypes;
		}

		static int getEnumValueFromString(String^ value , List<String^>^ strings)
		{
			int result = -1;

			for( int counter = 0; counter < strings->Count; counter++)
			{
				if(value == strings[counter])
				{
					result = counter;
				}
			}

			return result;
		}

	};
}