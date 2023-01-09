#pragma once
/* clang -march=native -dM -E - < /dev/null */

#if defined(__x86_64) || defined(__x86_64__) || defined(_M_AMD64) || defined(_WIN64)
#   define IS_64BIT true
#endif

#if defined(__AVX2__)
#   define USE_AVX2 true
#endif

#if defined(__AVX512BW__) \
 || defined(__AVX512CD__) \
 || defined(__AVX512DQ__) \
 || defined(__AVX512F__)  \
 || defined(__AVX512VL__)
#   define USE_AVX512 true
#endif

#if (defined(__SSE__) || defined(_M_AMD64) || (_M_IX86_FP >= 1)) && !defined(USE_SSE)
#   define USE_SSE true
#endif

#if (defined(__SSE2__) || defined(_M_AMD64) || (_M_IX86_FP >= 2)) && !defined(USE_SSE2)
#   define USE_SSE2 true
#endif

#if (defined(__SSE3__) || defined(_M_AMD64) || (_M_IX86_FP >= 3)) && !defined(USE_SSE3)
#   define USE_SSE3 true
#endif

#if (defined (__SSSE3__) || defined(_M_AMD64) || (_M_IX86_FP >= 4)) && !defined(USE_SSSE3)
#   define USE_SSSE3 true
#endif

#if (defined(__SSE4_1__) || defined(_M_AMD64) || (_M_IX86_FP >= 5)) && !defined(USE_SSE41)
#   define USE_SSE41 true
#endif

#if defined(__ARM_NEON) || defined(__ARM_NEON__)
#   define USE_NEON true
#endif


static const char NNUE_CONFIG[] = ""
#ifdef USE_AVX512
    "avx512/"
#elif defined(USE_AVX2)
    "avx2/"
#endif
#ifdef USE_MMX
    "mmx/"
#endif
#ifdef USE_NEON
    "neon/"
#endif
#ifdef USE_SSE
    "sse/"
#endif
#ifdef USE_SSE2
    "sse2/"
#endif
#ifdef USE_SSE3
    "sse3/"
#endif
#ifdef USE_SSE41
    "sse4.1/"
#endif
#ifdef USE_SSSE3
    "ssse3/"
#endif
#ifdef USE_VNNI
    "vnni/"
#endif

#ifdef IS_64BIT
    "64"
#else
    "32"
#endif
    ;
