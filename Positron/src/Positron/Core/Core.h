#pragma once

#ifdef POSITRON_PLATFORM_WINDOWS
#  ifdef POSITRON_BUILD_DLL
#    define POSITRON_API __declspec(dllexport)
#  else
#    define POSITRON_API __declspec(dllimport)
#  endif // POSITRON_BUILD_DLL
#else
#  error Positron only supports Windows!
#endif // POSITRON_PLATFORM_WINDOWS

#ifdef POSITRON_ENABLE_ASSERTS
#  define ASSERT(x,...) { if(!(x)) { LOG_ERROR("Assertion Failed: {}", __VA_ARGS__); __debugbreak(); } }
#  define CORE_ASSERT(x,...) { if(!(x)) { CORE_ERROR("Assertion Failed: {}", __VA_ARGS__); __debugbreak(); } }
#else
#  define ASSERT(x,...)
#  define CORE_ASSERT(x,...)
#endif //  POSITRON_ENABLE_ASSERTS

//Syntactic sugars
#define BIT(x) (1 << x)
#define GET(x) { return x; }
#define SET(x,y) { x = y; }
#define F(...) std::format(__VA_ARGS__)