#pragma once
#include "ConversionExport.h"
#include "ConversionInterface.h"
#include <string>
#include <memory>

CONVERSION_API std::unique_ptr<ConvertInterface> GetConvertInstance();