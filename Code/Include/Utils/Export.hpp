#pragma once

// Case : Platforms : Window / Linux, Build : shared or static

#if defined(_DEBUG) || defined(DEBUG) || defined(__DEBUG__) || defined(__DEBUG)
	#ifndef KRHI_DEBUG
		#define KRHI_DEBUG
	#endif
#else 
	#define KRHI_RELEASE 
#endif

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