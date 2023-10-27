#pragma once
#include <vector>
#include <string>
#include "ConversionExport.h"

class ConvertInterface
{
public:
	ConvertInterface() { }
	virtual ~ConvertInterface() { }
	virtual bool Convertto(const std::string source, const std::string destination) = 0;
};


