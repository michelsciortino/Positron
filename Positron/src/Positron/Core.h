#pragma once


#ifdef POSITRON_PLATFORM_WINDOWS
	#ifdef POSITRON_BUILD_DLL
		#define POSITRON_API __declspec(dllexport)
	#else
		#define POSITRON_API __declspec(dllimport)
	#endif
#else
	#error Positron only supports Windows!
#endif