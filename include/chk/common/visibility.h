#pragma once

#if defined _WIN32 || defined __CYGWIN__
#    define CHK_COMMON_HELPER_DLL_IMPORT __declspec(dllimport)
#    define CHK_COMMON_HELPER_DLL_EXPORT __declspec(dllexport)
#    define CHK_COMMON_HELPER_DLL_LOCAL
#else
#    if __GNUC__ >= 4
#        define CHK_COMMON_HELPER_DLL_IMPORT                                   \
            __attribute__((visibility("default")))
#        define CHK_COMMON_HELPER_DLL_EXPORT                                   \
            __attribute__((visibility("default")))
#        define CHK_COMMON_HELPER_DLL_LOCAL                                    \
            __attribute__((visibility("hidden")))
#    else
#        define CHK_COMMON_HELPER_DLL_IMPORT
#        define CHK_COMMON_HELPER_DLL_EXPORT
#        define CHK_COMMON_HELPER_DLL_LOCAL
#    endif
#endif

#ifdef CHK_COMMON_DLL
#    ifdef CHK_COMMON_DLL_EXPORTS
#        define CHK_COMMON_API CHK_COMMON_HELPER_DLL_EXPORT
#    else
#        define CHK_COMMON_API CHK_COMMON_HELPER_DLL_IMPORT
#    endif
#    define CHK_COMMON_LOCAL CHK_COMMON_HELPER_DLL_LOCAL
#else
#    define CHK_COMMON_API
#    define CHK_COMMON_LOCAL
#endif
