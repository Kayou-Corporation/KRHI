#pragma once

#define KRHI_DEBUG

//#if defined(_DEBUG) || defined(DEBUG) || defined(__DEBUG__) || defined(__DEBUG) || defined(-DDEBUG)
//	#ifndef KRHI_DEBUG
//		#define KRHI_DEBUG
//	#endif
//#else 
//	#define KRHI_RELEASE 
//#endif

#if defined(_WIN32) || defined(_WIN64)
	#ifndef KRHI_INLINE
		#define KRHI_INLINE __forceinline
	#endif
#else
	#ifndef KRHI_INLINE
		#define KRHI_INLINE inline
	#endif
#endif