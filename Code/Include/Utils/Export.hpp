#pragma once


/**
 * @file Export.hpp
 * @brief Provide macro to export the library, can be export in shared, static and in both windows and linux
 */

#if defined(_WIN32) || defined(_WIN64)
	#if defined(KRHI_STATIC_DEFINE)
		#define KRHI_API
	#else
		#define KRHI_API __declspec(dllexport)
#endif
#else
	#if defined(KRHI_STATIC_DEFINE)
		#define KRHI_API
	#else
		#define KRHI_API __attribute__((visibility("default")))
	#endif
#endif
