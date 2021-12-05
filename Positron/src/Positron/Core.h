#pragma once

#ifdef POSITRON_PLATFORM_WINDOWS
#  ifdef POSITRON_BUILD_DLL
#    define POSITRON_API __declspec(dllexport)
#  else
#    define POSITRON_API __declspec(dllimport)
#  endif
#else
#  error Positron only supports Windows!
#endif

#define BIT(x) (1 << x)

#define GET(x) { return x; }

#define F(...) std::format(__VA_ARGS__)