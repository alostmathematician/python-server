#ifndef _MACROS_EXPORT_H_
#define MACROS_EXPORT_H_

#ifdef BUILD_SHARED_LIBS
#if defined(_WIN32)
#define QC_EXPORT __declspec(dllexport)
#define QC_IMPORT __declspec(dllimport)
#define QC_HIDDEN
#elif defined(__GNUC__)
#define QC_EXPORT __attribute__((__visibility__("default")))
#define QC_IMPORT
#define QC_HIDDEN __attribute__((__visibility__("hidden")))
#else
#define QC_EXPORT
#define QC_IMPORT
#define QC_HIDDEN
#endif
#endif // BUILD_SHARED_LIBS
#endif //MACROS_EXPORT_H_