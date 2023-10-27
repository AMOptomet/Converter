#pragma once

#pragma once
#ifdef CONVERSION_EXPORT
# define CONVERSION_API __declspec(dllexport)
#else
# define CONVERSION_API __declspec(dllimport)
#endif
