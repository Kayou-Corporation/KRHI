#pragma once

#if defined(_WIN32) || defined(_WIN64)
	#ifndef KRHI_INLINE
		#define KRHI_INLINE __forceinline
	#endif
#else
	#ifndef KRHI_INLINE
		#define KRHI_INLINE inline
	#endif
#endif