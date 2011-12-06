#ifndef RAUTO_CONVERTERS_H
#define RAUTO_CONVERTERS_H
#include <Rinternals.h>
#include <Rdefines.h>

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif


typedef enum { R_DEEP_COPY, R_DUPLICATE, R_REFERENCE } R_CopyLevel;

#define INTEGER_ELT(x, i)  INTEGER(x)[i]
#define REAL_ELT(x, i)     REAL(x)[i]


#define FAIL(msg)  { PROBLEM msg \
                     ERROR; \
                   }

typedef enum {NATIVE_ROUTINE, R_FUNCTION} CallableType;


int convertFromRToInt(SEXP obj);
SEXP convertDoubleToR(double x);
SEXP convertIntToR(int x);
SEXP convertIntArrayToR(int *x, int len);

char ** getRStringArray(SEXP);

/**
   Utility for converting a value from an enumeration to an R object 
   that is an integer scalar (vector of length 1) with a name
 */
SEXP createREnumerationValue(int val, const char * const *names, const int *values, int namesLength, const char *name);

/**
   Finalizer routine that cleans up the memory used when allocating a reference
   to a C-level structure. 
 */
void SimpleAllocFinalizer(SEXP ans);

void *Rfrom_Callbable(SEXP obj, const char * const TypeDefName, CallableType *type) ;


#ifdef __cplusplus
extern "C"
#endif
SEXP convertStringArrayToR(const char * const *x, int len);


void * R_getNativeReference(SEXP arg, const char *type, const char *tag);
SEXP R_createNativeReference(const void * const val, const char *className, const char *tagName);

#define R_GET_REF_TYPE(arg, class) \
    (class *) R_getNativeReference(arg, #class, #class)


#define R_MAKE_REF_TYPE(arg, class) \
     R_createNativeReference(arg, #class, #class)


#define DEREF_REF(x, type) * ((type *) R_getNativeReference((x), #type, #type))

#define DEREF_REF_PTR(x, type) ((type *) R_getNativeReference((x), #type, #type))


SEXP R_makeNames(const char *names[], int len);


SEXP copy_int_array_to_R(const int *x, int len);


SEXP R_make_var_reference(void *ref, char *type);
#define R_MAKE_VAR_REFERENCE(addr, type) R_make_var_reference((addr), type)
void *getVariableReference(SEXP arg, SEXP el, const char *type, const char *tag);

#define copy_int_array_to_R convertIntArrayToR


/* XXX This must be kept in synchronization with C++CastValues in R/classes.R in this package */
typedef enum {
    STATIC = 1,
    DYNAMIC,
    REINTERPRET,
    CONST
} CastType;

#ifdef __cplusplus
}
#endif

#endif
