#pragma once
#include <msclr/marshal_cppstd.h>
#include "ConversionInterface.h"
#include "ConversionFactory.h"

using namespace System;
using namespace System::Collections::Generic;

class ConvertInterface;

namespace ManagedLayer
{

	public ref class ToConvert
	{

	public:
		ToConvert();

				
		~ToConvert();
		
		

	bool Converting(String^ filePath1, String^ filePath2);

	static ToConvert^ getInstance()
	{
		return gcnew ToConvert();
	}

	private:

		
		
	};


}