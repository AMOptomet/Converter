#include "ManagedLayer.h"
#include <msclr/marshal_cppstd.h>
#include "ConversionInterface.h"
#include <iostream>
#include "Conversion.h"
#include "ConversionFactory.h"
using namespace std;
using namespace System;
using namespace System::Collections::Generic;


namespace ManagedLayer
{
	ToConvert::ToConvert()
	{
		
		
	}
	ToConvert::~ToConvert()
	{
		//delete _con;
	}

	bool ToConvert::Converting(String^ filePath1, String^ filePath2)
	{
		try
		{
			bool succes = false;
			msclr::interop::marshal_context context;
			std::string FilePath1 = context.marshal_as<std::string>(filePath1);
			std::string FilePath2 = context.marshal_as<std::string>(filePath2);
			ConvertInterface* con = new Conversions();
			
			succes = con->Convertto(FilePath1, FilePath2);
			return succes;


		}
		catch (System::Exception^ ex)
		{
			throw(ex);
		}
	}
	
}
