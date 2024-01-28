
#ifndef RESTC_CPP_EXPORT_H
#define RESTC_CPP_EXPORT_H

#ifdef RESTC_CPP_RESTC_CPP_STATIC_DEFINE
#  define RESTC_CPP_EXPORT
#  define RESTC_CPP_NO_EXPORT
#else
#  ifndef RESTC_CPP_EXPORT
#    ifdef restc_cpp_EXPORTS
        /* We are building this library */
#      define RESTC_CPP_EXPORT 
#    else
        /* We are using this library */
#      define RESTC_CPP_EXPORT 
#    endif
#  endif

#  ifndef RESTC_CPP_NO_EXPORT
#    define RESTC_CPP_NO_EXPORT 
#  endif
#endif

#ifndef RESTC_CPP_RESTC_CPP_DEPRECATED
#  define RESTC_CPP_RESTC_CPP_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef RESTC_CPP_RESTC_CPP_DEPRECATED_EXPORT
#  define RESTC_CPP_RESTC_CPP_DEPRECATED_EXPORT RESTC_CPP_EXPORT RESTC_CPP_RESTC_CPP_DEPRECATED
#endif

#ifndef RESTC_CPP_RESTC_CPP_DEPRECATED_NO_EXPORT
#  define RESTC_CPP_RESTC_CPP_DEPRECATED_NO_EXPORT RESTC_CPP_NO_EXPORT RESTC_CPP_RESTC_CPP_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef RESTC_CPP_RESTC_CPP_NO_DEPRECATED
#    define RESTC_CPP_RESTC_CPP_NO_DEPRECATED
#  endif
#endif

#endif /* RESTC_CPP_EXPORT_H */
