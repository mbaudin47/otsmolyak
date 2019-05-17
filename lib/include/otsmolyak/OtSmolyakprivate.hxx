
#ifndef OTSMOLYAK_PRIVATE_HXX
#define OTSMOLYAK_PRIVATE_HXX

/* From http://gcc.gnu.org/wiki/Visibility */
/* Generic helper definitions for shared library support */
#if defined _WIN32 || defined __CYGWIN__
#define OTSMOLYAK_HELPER_DLL_IMPORT __declspec(dllimport)
#define OTSMOLYAK_HELPER_DLL_EXPORT __declspec(dllexport)
#define OTSMOLYAK_HELPER_DLL_LOCAL
#else
#if __GNUC__ >= 4
#define OTSMOLYAK_HELPER_DLL_IMPORT __attribute__ ((visibility ("default")))
#define OTSMOLYAK_HELPER_DLL_EXPORT __attribute__ ((visibility ("default")))
#define OTSMOLYAK_HELPER_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
#else
#define OTSMOLYAK_HELPER_DLL_IMPORT
#define OTSMOLYAK_HELPER_DLL_EXPORT
#define OTSMOLYAK_HELPER_DLL_LOCAL
#endif
#endif

/* Now we use the generic helper definitions above to define OTSMOLYAK_API and OTSMOLYAK_LOCAL.
 * OTSMOLYAK_API is used for the public API symbols. It either DLL imports or DLL exports (or does nothing for static build)
 * OTSMOLYAK_LOCAL is used for non-api symbols. */

#ifndef OTSMOLYAK_STATIC /* defined if OT is compiled as a DLL */
#ifdef OTSMOLYAK_DLL_EXPORTS /* defined if we are building the OT DLL (instead of using it) */
#define OTSMOLYAK_API OTSMOLYAK_HELPER_DLL_EXPORT
#else
#define OTSMOLYAK_API OTSMOLYAK_HELPER_DLL_IMPORT
#endif /* OTSMOLYAK_DLL_EXPORTS */
#define OTSMOLYAK_LOCAL OTSMOLYAK_HELPER_DLL_LOCAL
#else /* OTSMOLYAK_STATIC is defined: this means OT is a static lib. */
#define OTSMOLYAK_API
#define OTSMOLYAK_LOCAL
#endif /* !OTSMOLYAK_STATIC */


#endif // OTSMOLYAK_PRIVATE_HXX

