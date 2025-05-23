#pragma once

#if defined(KRHI_DEBUG_DEFINE)
	#ifndef KRHI_DEBUG
		#define KRHI_DEBUG
	#endif
#else 
	#define KRHI_RELEASE 
#endif

#if defined(_MSC_VER)
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