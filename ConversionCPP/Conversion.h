#pragma once
#include < vector >
#include < string >
#include "ConversionInterface.h"


class CONVERSION_API Conversions : public ConvertInterface
{
public:
	Conversions()
	{

	};
	~Conversions()
	{

	};

	bool Convertto(const std::string source, const std::string destination);
private:

};
