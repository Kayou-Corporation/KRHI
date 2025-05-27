#pragma once

#include "Common/APIInterface.hpp"

/**
 * @file Macros.hpp
 * @brief Provide few macros, both in windows and linux
 */

 /**
  * @brief Macros to know the type of compilation
  */
#if defined(KRHI_DEBUG_DEFINE)
	#ifndef KRHI_DEBUG
		#define KRHI_DEBUG
	#endif
#else 
	#define KRHI_RELEASE 
#endif

/**
 * @brief Macro to define inline and it's variant depending on the platform
 */
#if defined(_MSC_VER) && defined(__clang__)
	#define INLINE inline
	#define FORCE_INLINE inline __attribute__((always_inline))
	#define NO_INLINE __attribute__((noinline))
#elif defined(_MSC_VER) 
	#define INLINE __inline
	#define FORCE_INLINE __forceinline
	#define NO_INLINE __declspec(noinline)
#elif defined(__GNUC__) || defined(__clang__)
	#define INLINE inline
	#define FORCE_INLINE inline __attribute__((always_inline))
	#define NO_INLINE __attribute__((noinline))
#else
	#define INLINE inline
	#define FORCE_INLINE inline
	#define NO_INLINE
#endif
