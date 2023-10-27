#include "STEPControl_Reader.hxx"
#include "IGESControl_Reader.hxx"
#include "StlAPI_Writer.hxx"
#include "TopoDS_Shape.hxx"
#include "Standard_ConstructionError.hxx"
#include <BRep_Builder.hxx>
#include <BRepMesh_IncrementalMesh.hxx>
#include "lib3mf_implicit.hpp"
#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include "Conversion.h"
#include "ConversionInterface.h"
#include < iostream >
#include <tuple>
#include <memory>



#ifndef __GNUC__
#include <Windows.h>
#endif

std::unique_ptr<ConvertInterface> GetConvertInstance()
{
	try
	{
		return std::move(std::unique_ptr<ConvertInterface>(new Conversions()));
	}
	catch (const std::exception& ex)
	{
		throw ex;
	}

}


std::string FindExtension(std::string filename) {
	// this emulates Windows' PathFindExtension
	std::string::size_type idx;
	idx = filename.rfind('.');

	if (idx != std::string::npos)
	{
		return filename.substr(idx);
	}
	else
	{
		return "";
	}
}

std::string concatenateStrings(std::string filename1, std::string filename2) {
	std::string result(filename1);
	result += filename2;
	return result;
	
}



bool Conversions::Convertto(const std::string source, const std::string destination)
{

	bool success = false;
	const Standard_CString source1 = source.c_str();
	const Standard_CString destination1 = destination.c_str();
	/*const Standard_CString txtfile = "\\screw.stl";
	std::string ConcatenatedString = concatenateStrings(destination1, txtfile);
	const Standard_CString ConcatenatedStringg = ConcatenatedString.c_str();*/
	if ((std::string(source).substr(std::string(source).find_last_of(".") + 1) == "step" || std::string(source).substr(std::string(source).find_last_of(".") + 1) == "stp" || std::string(source).substr(std::string(source).find_last_of(".") + 1) == "STEP" || std::string(source).substr(std::string(source).find_last_of(".") + 1) == "STP")&& (std::string(destination1).substr(std::string(destination1).find_last_of(".") + 1) == "STL" || std::string(destination1).substr(std::string(destination1).find_last_of(".") + 1) == "stl"))

	{
		STEPControl_Reader reader;

		reader.ReadFile(source1);

		reader.TransferRoots();
		TopoDS_Shape stepShape = reader.OneShape();
		BRepMesh_IncrementalMesh mesh(stepShape, 0.1, Standard_False, 0.5, Standard_True);
		try
		{
			StlAPI_Writer writer;
			writer.Write(stepShape, destination1);
			success = true;
		}
		catch (Standard_ConstructionError& e)
		{
			std::cout << e.GetMessageString() << std::endl;
		}
	}
	else if ((std::string(source).substr(std::string(source).find_last_of(".") + 1) == "iges" || std::string(source).substr(std::string(source).find_last_of(".") + 1)=="igs" || std::string(source).substr(std::string(source).find_last_of(".") + 1) == "IGES" || std::string(source).substr(std::string(source).find_last_of(".") + 1) == "IGS") && (std::string(destination1).substr(std::string(destination1).find_last_of(".") + 1) == "STL" || std::string(destination1).substr(std::string(destination1).find_last_of(".") + 1) == "stl"))

	{
		IGESControl_Reader reader;
		reader.ReadFile(source1);
		reader.TransferRoots();
		TopoDS_Shape stepShape = reader.OneShape();
		BRepMesh_IncrementalMesh mesh(stepShape, 0.1, Standard_False, 0.5, Standard_True);
		try
		{
			StlAPI_Writer writer;
			writer.Write(stepShape, destination1);
			success = true;
		}
		catch (Standard_ConstructionError& e)
		{
			std::cout << e.GetMessageString() << std::endl;
		}
	}
	else if (std::string(source).substr(std::string(source).find_last_of(".") + 1) == "stl" || std::string(source).substr(std::string(source).find_last_of(".") + 1) == "STL")
	{
		Lib3MF::PWrapper wrapper = Lib3MF::CWrapper::loadLibrary();


		// Extract Extension of filename
		std::string sReaderName;
		std::string sWriterName;
		std::string sNewExtension;
		std::string sExtension = FindExtension(source);
		std::transform(sExtension.begin(), sExtension.end(), sExtension.begin(), ::tolower);

		// Which Reader and Writer classes do we need?

		sReaderName = "stl";
		sWriterName = "3mf";
		sNewExtension = ".3mf";


		if (sReaderName.length() == 0) {
			std::cout << "unknown input file extension:" << sExtension << std::endl;

		}

		// Create new filename
		std::string sOutputFilename = destination;
		sOutputFilename.erase(sOutputFilename.length() - sExtension.length());
		sOutputFilename += sNewExtension;

		Lib3MF::PModel model = wrapper->CreateModel();
		Lib3MF::PReader reader = model->QueryReader(sReaderName);
		// Import Model from File
		std::cout << "reading " << source << "..." << std::endl;

		reader->ReadFromFile(source);


		Lib3MF::PWriter writer = model->QueryWriter(sWriterName);
		std::cout << "writing " << sOutputFilename << "..." << std::endl;

		writer->WriteToFile(sOutputFilename);
		success = true;

	}
	else if (std::string(source).substr(std::string(source).find_last_of(".") + 1) == "3mf" || std::string(source).substr(std::string(source).find_last_of(".") + 1) == "3MF")
	{
		Lib3MF::PWrapper wrapper = Lib3MF::CWrapper::loadLibrary();


		// Extract Extension of filename
		std::string sReaderName;
		std::string sWriterName;
		std::string sNewExtension;
		std::string sExtension = FindExtension(source);
		std::transform(sExtension.begin(), sExtension.end(), sExtension.begin(), ::tolower);

		// Which Reader and Writer classes do we need?

		sReaderName = "3mf";
		sWriterName = "stl";
		sNewExtension = ".stl";

		if (sReaderName.length() == 0) {
			std::cout << "unknown input file extension:" << sExtension << std::endl;

		}

		// Create new filename
		std::string sOutputFilename = destination;
		sOutputFilename.erase(sOutputFilename.length() - sExtension.length());
		sOutputFilename += sNewExtension;

		Lib3MF::PModel model = wrapper->CreateModel();
		Lib3MF::PReader reader = model->QueryReader(sReaderName);
		// Import Model from File
		std::cout << "reading " << source << "..." << std::endl;

		reader->ReadFromFile(source);


		Lib3MF::PWriter writer = model->QueryWriter(sWriterName);
		std::cout << "writing " << sOutputFilename << "..." << std::endl;

		writer->WriteToFile(sOutputFilename);
		success = true;

	}
	
		return success;


}




