#include <sys/time.h> 
#include <sys/resource.h> 
#include "RConverters.h" 


#ifdef __cplusplus
extern "C"
#endif
SEXP
copy___fd_mask_array_to_R ( const const __fd_mask * array,  size_t len  )
{
	int i;
	SEXP r_ans;
	r_ans = NEW_NUMERIC ( len ) ;
	
	PROTECT(r_ans);
	for(i = 0; i < len; i++) {
		 REAL (r_ans)[i] = ( double ) array[i];
	}
	UNPROTECT(1);
	return(r_ans);
} 
#ifdef __cplusplus
extern "C"
#endif
SEXP R_copyStruct_fd_set ( const fd_set *value)
{
	SEXP r_ans = R_NilValue, klass;
	klass = MAKE_CLASS("fd_set");
	if(klass == R_NilValue) {
	   PROBLEM "Cannot find R class fd_set "
	    ERROR;
	}
	

	PROTECT(klass);
	PROTECT(r_ans = NEW(klass));

	PROTECT(r_ans = SET_SLOT(r_ans, Rf_install("__fds_bits"), copy___fd_mask_array_to_R ( value -> __fds_bits ,  32 ) ));
	UNPROTECT( 3 );
	
	return(r_ans);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_fd_setPtr_get___fds_bits (SEXP r_obj  )
{
	const fd_set *obj ;
	obj = ( const fd_set * )  R_getNativeReference(r_obj, "fd_set", "fd_setPtr") ;
	return( copy___fd_mask_array_to_R ( obj -> __fds_bits ,  32 ) );
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_fd_setPtr_set___fds_bits (SEXP r_obj , SEXP r_value )
{
	fd_set *obj ;
	obj = ( fd_set * )  R_getNativeReference(r_obj, "fd_set", "fd_setPtr") ;
	memcpy( obj ,  r_value , sizeof( obj [0]) *  32 );
	return(r_obj);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_coerce_fd_set_fd_setPtr ( SEXP r_from )
{
	fd_set * ans ;
	
	SEXP tmp;
	
	ans = ( fd_set * ) malloc( sizeof( fd_set ));
	tmp = GET_SLOT(r_from, Rf_install("__fds_bits"));
	memcpy( ans ,  tmp , sizeof( ans [0]) *  32 );
	
	return ( R_createNativeReference( (void *)  ans ,  "fd_setPtr" , "fd_setPtr" ) );
}
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_coerce_fd_setPtr_fd_set ( SEXP from )
{
	fd_set * ans ;
	ans = (fd_set *) R_getNativeReference(from, "fd_set", "fd_setPtr");
	return( R_copyStruct_fd_set ( ans ) );
} 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_new_fd_set ()
{
	SEXP r_ans = R_NilValue;
	fd_set * ans;
	
	ans = ( fd_set *) calloc (1, sizeof( fd_set ));
	 r_ans =  R_createNativeReference( (void *)  ans ,  "fd_setPtr" , "fd_setPtr" ) ;
	return(r_ans);
} 
#ifdef __cplusplus
extern "C"
#endif
void
R_free_fd_set_finalizer (SEXP val)
{
	fd_set * ans = NULL;
	ans = ( fd_set * ) R_ExternalPtrAddr(val);
	 if(ans) { fprintf(stderr, "freeing fd_set \n"); free(ans);}
} 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_free_fd_set (SEXP val)
{
	fd_set * ans = NULL;
	ans =  (fd_set *) R_getNativeReference(val, "fd_setPtr", "fd_setPtr") ;
	
	 if(ans) { fprintf(stderr, "freeing fd_set \n"); free(ans);}
	return(ScalarLogical(ans ? TRUE : FALSE));
} 
#ifdef __cplusplus
extern "C"
#endif
SEXP R_copyStruct_timeval ( const struct  timeval *value)
{
	SEXP r_ans = R_NilValue, klass;
	klass = MAKE_CLASS("timeval");
	if(klass == R_NilValue) {
	   PROBLEM "Cannot find R class timeval "
	    ERROR;
	}
	

	PROTECT(klass);
	PROTECT(r_ans = NEW(klass));

	PROTECT(r_ans = SET_SLOT(r_ans, Rf_install("tv_sec"), ScalarReal ( value -> tv_sec ) ));
	PROTECT(r_ans = SET_SLOT(r_ans, Rf_install("tv_usec"), ScalarReal ( value -> tv_usec ) ));
	UNPROTECT( 4 );
	
	return(r_ans);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_timevalPtr_get_tv_sec (SEXP r_obj  )
{
	const struct  timeval *obj ;
	obj = ( const struct  timeval * )  R_getNativeReference(r_obj, "timeval", "timevalPtr") ;
	return( ScalarReal ( obj -> tv_sec ) );
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_timevalPtr_get_tv_usec (SEXP r_obj  )
{
	const struct  timeval *obj ;
	obj = ( const struct  timeval * )  R_getNativeReference(r_obj, "timeval", "timevalPtr") ;
	return( ScalarReal ( obj -> tv_usec ) );
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_timevalPtr_set_tv_sec (SEXP r_obj , SEXP r_value )
{
	struct  timeval *obj ;
	__time_t value ;
	value =  asInteger( r_value ) ;
	obj = ( struct  timeval * )  R_getNativeReference(r_obj, "timeval", "timevalPtr") ;
	obj -> tv_sec = value ;
	return(r_obj);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_timevalPtr_set_tv_usec (SEXP r_obj , SEXP r_value )
{
	struct  timeval *obj ;
	__suseconds_t value ;
	value =  asInteger( r_value ) ;
	obj = ( struct  timeval * )  R_getNativeReference(r_obj, "timeval", "timevalPtr") ;
	obj -> tv_usec = value ;
	return(r_obj);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_coerce_timeval_timevalPtr ( SEXP r_from )
{
	struct  timeval * ans ;
	
	SEXP tmp;
	
	ans = ( struct  timeval * ) malloc( sizeof( struct  timeval ));
	tmp = GET_SLOT(r_from, Rf_install("tv_sec"));
	ans->tv_sec = asInteger( tmp ) ;
	tmp = GET_SLOT(r_from, Rf_install("tv_usec"));
	ans->tv_usec = asInteger( tmp ) ;
	
	return ( R_createNativeReference( (void *)  ans ,  "timevalPtr" , "timevalPtr" ) );
}
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_coerce_timevalPtr_timeval ( SEXP from )
{
	struct  timeval * ans ;
	ans = (struct  timeval *) R_getNativeReference(from, "timeval", "timevalPtr");
	return( R_copyStruct_timeval ( ans ) );
} 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_new_timeval ()
{
	SEXP r_ans = R_NilValue;
	struct  timeval * ans;
	
	ans = ( struct  timeval *) calloc (1, sizeof( struct  timeval ));
	 r_ans =  R_createNativeReference( (void *)  ans ,  "timevalPtr" , "timevalPtr" ) ;
	return(r_ans);
} 
#ifdef __cplusplus
extern "C"
#endif
void
R_free_timeval_finalizer (SEXP val)
{
	struct  timeval * ans = NULL;
	ans = ( struct  timeval * ) R_ExternalPtrAddr(val);
	 if(ans) { fprintf(stderr, "freeing timeval \n"); free(ans);}
} 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_free_timeval (SEXP val)
{
	struct  timeval * ans = NULL;
	ans =  (struct  timeval *) R_getNativeReference(val, "timevalPtr", "timevalPtr") ;
	
	 if(ans) { fprintf(stderr, "freeing timeval \n"); free(ans);}
	return(ScalarLogical(ans ? TRUE : FALSE));
} 
#ifdef __cplusplus
extern "C"
#endif
SEXP R_copyStruct_timespec ( const struct  timespec *value)
{
	SEXP r_ans = R_NilValue, klass;
	klass = MAKE_CLASS("timespec");
	if(klass == R_NilValue) {
	   PROBLEM "Cannot find R class timespec "
	    ERROR;
	}
	

	PROTECT(klass);
	PROTECT(r_ans = NEW(klass));

	PROTECT(r_ans = SET_SLOT(r_ans, Rf_install("tv_sec"), ScalarReal ( value -> tv_sec ) ));
	PROTECT(r_ans = SET_SLOT(r_ans, Rf_install("tv_nsec"), ScalarReal ( value -> tv_nsec ) ));
	UNPROTECT( 4 );
	
	return(r_ans);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_timespecPtr_get_tv_sec (SEXP r_obj  )
{
	const struct  timespec *obj ;
	obj = ( const struct  timespec * )  R_getNativeReference(r_obj, "timespec", "timespecPtr") ;
	return( ScalarReal ( obj -> tv_sec ) );
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_timespecPtr_get_tv_nsec (SEXP r_obj  )
{
	const struct  timespec *obj ;
	obj = ( const struct  timespec * )  R_getNativeReference(r_obj, "timespec", "timespecPtr") ;
	return( ScalarReal ( obj -> tv_nsec ) );
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_timespecPtr_set_tv_sec (SEXP r_obj , SEXP r_value )
{
	struct  timespec *obj ;
	__time_t value ;
	value =  asInteger( r_value ) ;
	obj = ( struct  timespec * )  R_getNativeReference(r_obj, "timespec", "timespecPtr") ;
	obj -> tv_sec = value ;
	return(r_obj);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_timespecPtr_set_tv_nsec (SEXP r_obj , SEXP r_value )
{
	struct  timespec *obj ;
	long int value ;
	value =  asInteger( r_value ) ;
	obj = ( struct  timespec * )  R_getNativeReference(r_obj, "timespec", "timespecPtr") ;
	obj -> tv_nsec = value ;
	return(r_obj);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_coerce_timespec_timespecPtr ( SEXP r_from )
{
	struct  timespec * ans ;
	
	SEXP tmp;
	
	ans = ( struct  timespec * ) malloc( sizeof( struct  timespec ));
	tmp = GET_SLOT(r_from, Rf_install("tv_sec"));
	ans->tv_sec = asInteger( tmp ) ;
	tmp = GET_SLOT(r_from, Rf_install("tv_nsec"));
	ans->tv_nsec = asInteger( tmp ) ;
	
	return ( R_createNativeReference( (void *)  ans ,  "timespecPtr" , "timespecPtr" ) );
}
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_coerce_timespecPtr_timespec ( SEXP from )
{
	struct  timespec * ans ;
	ans = (struct  timespec *) R_getNativeReference(from, "timespec", "timespecPtr");
	return( R_copyStruct_timespec ( ans ) );
} 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_new_timespec ()
{
	SEXP r_ans = R_NilValue;
	const struct  timespec * ans;
	
	ans = ( const struct  timespec *) calloc (1, sizeof( const struct  timespec ));
	 r_ans =  R_createNativeReference( (void *)  ans ,  "timespecPtr" , "timespecPtr" ) ;
	return(r_ans);
} 
#ifdef __cplusplus
extern "C"
#endif
void
R_free_timespec_finalizer (SEXP val)
{
	struct  timespec * ans = NULL;
	ans = ( struct  timespec * ) R_ExternalPtrAddr(val);
	 if(ans) { fprintf(stderr, "freeing timespec \n"); free(ans);}
} 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_free_timespec (SEXP val)
{
	struct  timespec * ans = NULL;
	ans =  (struct  timespec *) R_getNativeReference(val, "timespecPtr", "timespecPtr") ;
	
	 if(ans) { fprintf(stderr, "freeing timespec \n"); free(ans);}
	return(ScalarLogical(ans ? TRUE : FALSE));
} 
#ifdef __cplusplus
extern "C"
#endif
SEXP
copy_long_unsigned_int_array_to_R ( const const long unsigned int * array,  size_t len  )
{
	int i;
	SEXP r_ans;
	r_ans = NEW_NUMERIC ( len ) ;
	
	PROTECT(r_ans);
	for(i = 0; i < len; i++) {
		 REAL (r_ans)[i] = ( double ) array[i];
	}
	UNPROTECT(1);
	return(r_ans);
} 
#ifdef __cplusplus
extern "C"
#endif
SEXP R_copyStruct___sigset_t ( const __sigset_t *value)
{
	SEXP r_ans = R_NilValue, klass;
	klass = MAKE_CLASS("__sigset_t");
	if(klass == R_NilValue) {
	   PROBLEM "Cannot find R class __sigset_t "
	    ERROR;
	}
	

	PROTECT(klass);
	PROTECT(r_ans = NEW(klass));

	PROTECT(r_ans = SET_SLOT(r_ans, Rf_install("__val"), copy_long_unsigned_int_array_to_R ( value -> __val ,  32 ) ));
	UNPROTECT( 3 );
	
	return(r_ans);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R___sigset_tPtr_get___val (SEXP r_obj  )
{
	const __sigset_t *obj ;
	obj = ( const __sigset_t * )  R_getNativeReference(r_obj, "__sigset_t", "__sigset_tPtr") ;
	return( copy_long_unsigned_int_array_to_R ( obj -> __val ,  32 ) );
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R___sigset_tPtr_set___val (SEXP r_obj , SEXP r_value )
{
	__sigset_t *obj ;
	obj = ( __sigset_t * )  R_getNativeReference(r_obj, "__sigset_t", "__sigset_tPtr") ;
	memcpy( obj ,  r_value , sizeof( obj [0]) *  32 );
	return(r_obj);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_coerce___sigset_t___sigset_tPtr ( SEXP r_from )
{
	__sigset_t * ans ;
	
	SEXP tmp;
	
	ans = ( __sigset_t * ) malloc( sizeof( __sigset_t ));
	tmp = GET_SLOT(r_from, Rf_install("__val"));
	memcpy( ans ,  tmp , sizeof( ans [0]) *  32 );
	
	return ( R_createNativeReference( (void *)  ans ,  "__sigset_tPtr" , "__sigset_tPtr" ) );
}
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_coerce___sigset_tPtr___sigset_t ( SEXP from )
{
	__sigset_t * ans ;
	ans = (__sigset_t *) R_getNativeReference(from, "__sigset_t", "__sigset_tPtr");
	return( R_copyStruct___sigset_t ( ans ) );
} 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_new___sigset_t ()
{
	SEXP r_ans = R_NilValue;
	const __sigset_t * ans;
	
	ans = ( const __sigset_t *) calloc (1, sizeof( const __sigset_t ));
	 r_ans =  R_createNativeReference( (void *)  ans ,  "__sigset_tPtr" , "__sigset_tPtr" ) ;
	return(r_ans);
} 
#ifdef __cplusplus
extern "C"
#endif
void
R_free___sigset_t_finalizer (SEXP val)
{
	__sigset_t * ans = NULL;
	ans = ( __sigset_t * ) R_ExternalPtrAddr(val);
	 if(ans) { fprintf(stderr, "freeing __sigset_t \n"); free(ans);}
} 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_free___sigset_t (SEXP val)
{
	__sigset_t * ans = NULL;
	ans =  (__sigset_t *) R_getNativeReference(val, "__sigset_tPtr", "__sigset_tPtr") ;
	
	 if(ans) { fprintf(stderr, "freeing __sigset_t \n"); free(ans);}
	return(ScalarLogical(ans ? TRUE : FALSE));
} 
#ifdef __cplusplus
extern "C"
#endif
SEXP R_copyStruct_timezone ( const struct  timezone *value)
{
	SEXP r_ans = R_NilValue, klass;
	klass = MAKE_CLASS("timezone");
	if(klass == R_NilValue) {
	   PROBLEM "Cannot find R class timezone "
	    ERROR;
	}
	

	PROTECT(klass);
	PROTECT(r_ans = NEW(klass));

	PROTECT(r_ans = SET_SLOT(r_ans, Rf_install("tz_minuteswest"), ScalarInteger ( value -> tz_minuteswest ) ));
	PROTECT(r_ans = SET_SLOT(r_ans, Rf_install("tz_dsttime"), ScalarInteger ( value -> tz_dsttime ) ));
	UNPROTECT( 4 );
	
	return(r_ans);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_timezonePtr_get_tz_minuteswest (SEXP r_obj  )
{
	const struct  timezone *obj ;
	obj = ( const struct  timezone * )  R_getNativeReference(r_obj, "timezone", "timezonePtr") ;
	return( ScalarInteger ( obj -> tz_minuteswest ) );
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_timezonePtr_get_tz_dsttime (SEXP r_obj  )
{
	const struct  timezone *obj ;
	obj = ( const struct  timezone * )  R_getNativeReference(r_obj, "timezone", "timezonePtr") ;
	return( ScalarInteger ( obj -> tz_dsttime ) );
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_timezonePtr_set_tz_minuteswest (SEXP r_obj , SEXP r_value )
{
	struct  timezone *obj ;
	int value ;
	value =  asInteger( r_value ) ;
	obj = ( struct  timezone * )  R_getNativeReference(r_obj, "timezone", "timezonePtr") ;
	obj -> tz_minuteswest = value ;
	return(r_obj);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_timezonePtr_set_tz_dsttime (SEXP r_obj , SEXP r_value )
{
	struct  timezone *obj ;
	int value ;
	value =  asInteger( r_value ) ;
	obj = ( struct  timezone * )  R_getNativeReference(r_obj, "timezone", "timezonePtr") ;
	obj -> tz_dsttime = value ;
	return(r_obj);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_coerce_timezone_timezonePtr ( SEXP r_from )
{
	struct  timezone * ans ;
	
	SEXP tmp;
	
	ans = ( struct  timezone * ) malloc( sizeof( struct  timezone ));
	tmp = GET_SLOT(r_from, Rf_install("tz_minuteswest"));
	ans->tz_minuteswest = asInteger( tmp ) ;
	tmp = GET_SLOT(r_from, Rf_install("tz_dsttime"));
	ans->tz_dsttime = asInteger( tmp ) ;
	
	return ( R_createNativeReference( (void *)  ans ,  "timezonePtr" , "timezonePtr" ) );
}
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_coerce_timezonePtr_timezone ( SEXP from )
{
	struct  timezone * ans ;
	ans = (struct  timezone *) R_getNativeReference(from, "timezone", "timezonePtr");
	return( R_copyStruct_timezone ( ans ) );
} 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_new_timezone ()
{
	SEXP r_ans = R_NilValue;
	const struct  timezone * ans;
	
	ans = ( const struct  timezone *) calloc (1, sizeof( const struct  timezone ));
	 r_ans =  R_createNativeReference( (void *)  ans ,  "timezonePtr" , "timezonePtr" ) ;
	return(r_ans);
} 
#ifdef __cplusplus
extern "C"
#endif
void
R_free_timezone_finalizer (SEXP val)
{
	struct  timezone * ans = NULL;
	ans = ( struct  timezone * ) R_ExternalPtrAddr(val);
	 if(ans) { fprintf(stderr, "freeing timezone \n"); free(ans);}
} 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_free_timezone (SEXP val)
{
	struct  timezone * ans = NULL;
	ans =  (struct  timezone *) R_getNativeReference(val, "timezonePtr", "timezonePtr") ;
	
	 if(ans) { fprintf(stderr, "freeing timezone \n"); free(ans);}
	return(ScalarLogical(ans ? TRUE : FALSE));
} 
#ifdef __cplusplus
extern "C"
#endif
SEXP R_copyStruct_itimerval ( const struct  itimerval *value)
{
	SEXP r_ans = R_NilValue, klass;
	klass = MAKE_CLASS("itimerval");
	if(klass == R_NilValue) {
	   PROBLEM "Cannot find R class itimerval "
	    ERROR;
	}
	

	PROTECT(klass);
	PROTECT(r_ans = NEW(klass));

	PROTECT(r_ans = SET_SLOT(r_ans, Rf_install("it_interval"), R_copyStruct_timeval( &value -> it_interval ) ));
	PROTECT(r_ans = SET_SLOT(r_ans, Rf_install("it_value"), R_copyStruct_timeval( &value -> it_value ) ));
	UNPROTECT( 4 );
	
	return(r_ans);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_itimervalPtr_get_it_interval (SEXP r_obj  )
{
	const struct  itimerval *obj ;
	obj = ( const struct  itimerval * )  R_getNativeReference(r_obj, "itimerval", "itimervalPtr") ;
	return( R_copyStruct_timeval( &obj -> it_interval ) );
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_itimervalPtr_get_it_value (SEXP r_obj  )
{
	const struct  itimerval *obj ;
	obj = ( const struct  itimerval * )  R_getNativeReference(r_obj, "itimerval", "itimervalPtr") ;
	return( R_copyStruct_timeval( &obj -> it_value ) );
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_itimervalPtr_set_it_interval (SEXP r_obj , SEXP r_value )
{
	struct  itimerval *obj ;
	struct  timeval value ;
	value =  DEREF_REF( r_value ,  struct  timeval ) ;
	obj = ( struct  itimerval * )  R_getNativeReference(r_obj, "itimerval", "itimervalPtr") ;
	obj -> it_interval = value ;
	return(r_obj);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_itimervalPtr_set_it_value (SEXP r_obj , SEXP r_value )
{
	struct  itimerval *obj ;
	struct  timeval value ;
	value =  DEREF_REF( r_value ,  struct  timeval ) ;
	obj = ( struct  itimerval * )  R_getNativeReference(r_obj, "itimerval", "itimervalPtr") ;
	obj -> it_value = value ;
	return(r_obj);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_coerce_itimerval_itimervalPtr ( SEXP r_from )
{
	struct  itimerval * ans ;
	
	SEXP tmp;
	
	ans = ( struct  itimerval * ) malloc( sizeof( struct  itimerval ));
	tmp = GET_SLOT(r_from, Rf_install("it_interval"));
	ans->it_interval = DEREF_REF( tmp ,  struct  timeval ) ;
	tmp = GET_SLOT(r_from, Rf_install("it_value"));
	ans->it_value = DEREF_REF( tmp ,  struct  timeval ) ;
	
	return ( R_createNativeReference( (void *)  ans ,  "itimervalPtr" , "itimervalPtr" ) );
}
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_coerce_itimervalPtr_itimerval ( SEXP from )
{
	struct  itimerval * ans ;
	ans = (struct  itimerval *) R_getNativeReference(from, "itimerval", "itimervalPtr");
	return( R_copyStruct_itimerval ( ans ) );
} 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_new_itimerval ()
{
	SEXP r_ans = R_NilValue;
	struct  itimerval * ans;
	
	ans = ( struct  itimerval *) calloc (1, sizeof( struct  itimerval ));
	 r_ans =  R_createNativeReference( (void *)  ans ,  "itimervalPtr" , "itimervalPtr" ) ;
	return(r_ans);
} 
#ifdef __cplusplus
extern "C"
#endif
void
R_free_itimerval_finalizer (SEXP val)
{
	struct  itimerval * ans = NULL;
	ans = ( struct  itimerval * ) R_ExternalPtrAddr(val);
	 if(ans) { fprintf(stderr, "freeing itimerval \n"); free(ans);}
} 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_free_itimerval (SEXP val)
{
	struct  itimerval * ans = NULL;
	ans =  (struct  itimerval *) R_getNativeReference(val, "itimervalPtr", "itimervalPtr") ;
	
	 if(ans) { fprintf(stderr, "freeing itimerval \n"); free(ans);}
	return(ScalarLogical(ans ? TRUE : FALSE));
} 
#ifdef __cplusplus
extern "C"
#endif
SEXP R_copyStruct_rlimit ( const struct  rlimit *value)
{
	SEXP r_ans = R_NilValue, klass;
	klass = MAKE_CLASS("rlimit");
	if(klass == R_NilValue) {
	   PROBLEM "Cannot find R class rlimit "
	    ERROR;
	}
	

	PROTECT(klass);
	PROTECT(r_ans = NEW(klass));

	PROTECT(r_ans = SET_SLOT(r_ans, Rf_install("rlim_cur"), ScalarReal ( value -> rlim_cur ) ));
	PROTECT(r_ans = SET_SLOT(r_ans, Rf_install("rlim_max"), ScalarReal ( value -> rlim_max ) ));
	UNPROTECT( 4 );
	
	return(r_ans);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rlimitPtr_get_rlim_cur (SEXP r_obj  )
{
	const struct  rlimit *obj ;
	obj = ( const struct  rlimit * )  R_getNativeReference(r_obj, "rlimit", "rlimitPtr") ;
	return( ScalarReal ( obj -> rlim_cur ) );
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rlimitPtr_get_rlim_max (SEXP r_obj  )
{
	const struct  rlimit *obj ;
	obj = ( const struct  rlimit * )  R_getNativeReference(r_obj, "rlimit", "rlimitPtr") ;
	return( ScalarReal ( obj -> rlim_max ) );
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rlimitPtr_set_rlim_cur (SEXP r_obj , SEXP r_value )
{
	struct  rlimit *obj ;
	rlim_t value ;
	value =  asInteger( r_value ) ;
	obj = ( struct  rlimit * )  R_getNativeReference(r_obj, "rlimit", "rlimitPtr") ;
	obj -> rlim_cur = value ;
	return(r_obj);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rlimitPtr_set_rlim_max (SEXP r_obj , SEXP r_value )
{
	struct  rlimit *obj ;
	rlim_t value ;
	value =  asInteger( r_value ) ;
	obj = ( struct  rlimit * )  R_getNativeReference(r_obj, "rlimit", "rlimitPtr") ;
	obj -> rlim_max = value ;
	return(r_obj);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_coerce_rlimit_rlimitPtr ( SEXP r_from )
{
	struct  rlimit * ans ;
	
	SEXP tmp;
	
	ans = ( struct  rlimit * ) malloc( sizeof( struct  rlimit ));
	tmp = GET_SLOT(r_from, Rf_install("rlim_cur"));
	ans->rlim_cur = asInteger( tmp ) ;
	tmp = GET_SLOT(r_from, Rf_install("rlim_max"));
	ans->rlim_max = asInteger( tmp ) ;
	
	return ( R_createNativeReference( (void *)  ans ,  "rlimitPtr" , "rlimitPtr" ) );
}
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_coerce_rlimitPtr_rlimit ( SEXP from )
{
	struct  rlimit * ans ;
	ans = (struct  rlimit *) R_getNativeReference(from, "rlimit", "rlimitPtr");
	return( R_copyStruct_rlimit ( ans ) );
} 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_new_rlimit ()
{
	SEXP r_ans = R_NilValue;
	const struct  rlimit * ans;
	
	ans = ( const struct  rlimit *) calloc (1, sizeof( const struct  rlimit ));
	 r_ans =  R_createNativeReference( (void *)  ans ,  "rlimitPtr" , "rlimitPtr" ) ;
	return(r_ans);
} 
#ifdef __cplusplus
extern "C"
#endif
void
R_free_rlimit_finalizer (SEXP val)
{
	struct  rlimit * ans = NULL;
	ans = ( struct  rlimit * ) R_ExternalPtrAddr(val);
	 if(ans) { fprintf(stderr, "freeing rlimit \n"); free(ans);}
} 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_free_rlimit (SEXP val)
{
	struct  rlimit * ans = NULL;
	ans =  (struct  rlimit *) R_getNativeReference(val, "rlimitPtr", "rlimitPtr") ;
	
	 if(ans) { fprintf(stderr, "freeing rlimit \n"); free(ans);}
	return(ScalarLogical(ans ? TRUE : FALSE));
} 
#ifdef __cplusplus
extern "C"
#endif
SEXP R_copyStruct_rusage ( const struct  rusage *value)
{
	SEXP r_ans = R_NilValue, klass;
	klass = MAKE_CLASS("rusage");
	if(klass == R_NilValue) {
	   PROBLEM "Cannot find R class rusage "
	    ERROR;
	}
	

	PROTECT(klass);
	PROTECT(r_ans = NEW(klass));

	PROTECT(r_ans = SET_SLOT(r_ans, Rf_install("ru_utime"), R_copyStruct_timeval( &value -> ru_utime ) ));
	PROTECT(r_ans = SET_SLOT(r_ans, Rf_install("ru_stime"), R_copyStruct_timeval( &value -> ru_stime ) ));
	PROTECT(r_ans = SET_SLOT(r_ans, Rf_install("ru_maxrss"), ScalarReal ( value -> ru_maxrss ) ));
	PROTECT(r_ans = SET_SLOT(r_ans, Rf_install("ru_ixrss"), ScalarReal ( value -> ru_ixrss ) ));
	PROTECT(r_ans = SET_SLOT(r_ans, Rf_install("ru_idrss"), ScalarReal ( value -> ru_idrss ) ));
	PROTECT(r_ans = SET_SLOT(r_ans, Rf_install("ru_isrss"), ScalarReal ( value -> ru_isrss ) ));
	PROTECT(r_ans = SET_SLOT(r_ans, Rf_install("ru_minflt"), ScalarReal ( value -> ru_minflt ) ));
	PROTECT(r_ans = SET_SLOT(r_ans, Rf_install("ru_majflt"), ScalarReal ( value -> ru_majflt ) ));
	PROTECT(r_ans = SET_SLOT(r_ans, Rf_install("ru_nswap"), ScalarReal ( value -> ru_nswap ) ));
	PROTECT(r_ans = SET_SLOT(r_ans, Rf_install("ru_inblock"), ScalarReal ( value -> ru_inblock ) ));
	PROTECT(r_ans = SET_SLOT(r_ans, Rf_install("ru_oublock"), ScalarReal ( value -> ru_oublock ) ));
	PROTECT(r_ans = SET_SLOT(r_ans, Rf_install("ru_msgsnd"), ScalarReal ( value -> ru_msgsnd ) ));
	PROTECT(r_ans = SET_SLOT(r_ans, Rf_install("ru_msgrcv"), ScalarReal ( value -> ru_msgrcv ) ));
	PROTECT(r_ans = SET_SLOT(r_ans, Rf_install("ru_nsignals"), ScalarReal ( value -> ru_nsignals ) ));
	PROTECT(r_ans = SET_SLOT(r_ans, Rf_install("ru_nvcsw"), ScalarReal ( value -> ru_nvcsw ) ));
	PROTECT(r_ans = SET_SLOT(r_ans, Rf_install("ru_nivcsw"), ScalarReal ( value -> ru_nivcsw ) ));
	UNPROTECT( 18 );
	
	return(r_ans);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rusagePtr_get_ru_utime (SEXP r_obj  )
{
	const struct  rusage *obj ;
	obj = ( const struct  rusage * )  R_getNativeReference(r_obj, "rusage", "rusagePtr") ;
	return( R_copyStruct_timeval( &obj -> ru_utime ) );
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rusagePtr_get_ru_stime (SEXP r_obj  )
{
	const struct  rusage *obj ;
	obj = ( const struct  rusage * )  R_getNativeReference(r_obj, "rusage", "rusagePtr") ;
	return( R_copyStruct_timeval( &obj -> ru_stime ) );
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rusagePtr_get_ru_maxrss (SEXP r_obj  )
{
	const struct  rusage *obj ;
	obj = ( const struct  rusage * )  R_getNativeReference(r_obj, "rusage", "rusagePtr") ;
	return( ScalarReal ( obj -> ru_maxrss ) );
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rusagePtr_get_ru_ixrss (SEXP r_obj  )
{
	const struct  rusage *obj ;
	obj = ( const struct  rusage * )  R_getNativeReference(r_obj, "rusage", "rusagePtr") ;
	return( ScalarReal ( obj -> ru_ixrss ) );
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rusagePtr_get_ru_idrss (SEXP r_obj  )
{
	const struct  rusage *obj ;
	obj = ( const struct  rusage * )  R_getNativeReference(r_obj, "rusage", "rusagePtr") ;
	return( ScalarReal ( obj -> ru_idrss ) );
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rusagePtr_get_ru_isrss (SEXP r_obj  )
{
	const struct  rusage *obj ;
	obj = ( const struct  rusage * )  R_getNativeReference(r_obj, "rusage", "rusagePtr") ;
	return( ScalarReal ( obj -> ru_isrss ) );
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rusagePtr_get_ru_minflt (SEXP r_obj  )
{
	const struct  rusage *obj ;
	obj = ( const struct  rusage * )  R_getNativeReference(r_obj, "rusage", "rusagePtr") ;
	return( ScalarReal ( obj -> ru_minflt ) );
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rusagePtr_get_ru_majflt (SEXP r_obj  )
{
	const struct  rusage *obj ;
	obj = ( const struct  rusage * )  R_getNativeReference(r_obj, "rusage", "rusagePtr") ;
	return( ScalarReal ( obj -> ru_majflt ) );
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rusagePtr_get_ru_nswap (SEXP r_obj  )
{
	const struct  rusage *obj ;
	obj = ( const struct  rusage * )  R_getNativeReference(r_obj, "rusage", "rusagePtr") ;
	return( ScalarReal ( obj -> ru_nswap ) );
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rusagePtr_get_ru_inblock (SEXP r_obj  )
{
	const struct  rusage *obj ;
	obj = ( const struct  rusage * )  R_getNativeReference(r_obj, "rusage", "rusagePtr") ;
	return( ScalarReal ( obj -> ru_inblock ) );
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rusagePtr_get_ru_oublock (SEXP r_obj  )
{
	const struct  rusage *obj ;
	obj = ( const struct  rusage * )  R_getNativeReference(r_obj, "rusage", "rusagePtr") ;
	return( ScalarReal ( obj -> ru_oublock ) );
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rusagePtr_get_ru_msgsnd (SEXP r_obj  )
{
	const struct  rusage *obj ;
	obj = ( const struct  rusage * )  R_getNativeReference(r_obj, "rusage", "rusagePtr") ;
	return( ScalarReal ( obj -> ru_msgsnd ) );
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rusagePtr_get_ru_msgrcv (SEXP r_obj  )
{
	const struct  rusage *obj ;
	obj = ( const struct  rusage * )  R_getNativeReference(r_obj, "rusage", "rusagePtr") ;
	return( ScalarReal ( obj -> ru_msgrcv ) );
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rusagePtr_get_ru_nsignals (SEXP r_obj  )
{
	const struct  rusage *obj ;
	obj = ( const struct  rusage * )  R_getNativeReference(r_obj, "rusage", "rusagePtr") ;
	return( ScalarReal ( obj -> ru_nsignals ) );
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rusagePtr_get_ru_nvcsw (SEXP r_obj  )
{
	const struct  rusage *obj ;
	obj = ( const struct  rusage * )  R_getNativeReference(r_obj, "rusage", "rusagePtr") ;
	return( ScalarReal ( obj -> ru_nvcsw ) );
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rusagePtr_get_ru_nivcsw (SEXP r_obj  )
{
	const struct  rusage *obj ;
	obj = ( const struct  rusage * )  R_getNativeReference(r_obj, "rusage", "rusagePtr") ;
	return( ScalarReal ( obj -> ru_nivcsw ) );
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rusagePtr_set_ru_utime (SEXP r_obj , SEXP r_value )
{
	struct  rusage *obj ;
	struct  timeval value ;
	value =  DEREF_REF( r_value ,  struct  timeval ) ;
	obj = ( struct  rusage * )  R_getNativeReference(r_obj, "rusage", "rusagePtr") ;
	obj -> ru_utime = value ;
	return(r_obj);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rusagePtr_set_ru_stime (SEXP r_obj , SEXP r_value )
{
	struct  rusage *obj ;
	struct  timeval value ;
	value =  DEREF_REF( r_value ,  struct  timeval ) ;
	obj = ( struct  rusage * )  R_getNativeReference(r_obj, "rusage", "rusagePtr") ;
	obj -> ru_stime = value ;
	return(r_obj);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rusagePtr_set_ru_maxrss (SEXP r_obj , SEXP r_value )
{
	struct  rusage *obj ;
	long int value ;
	value =  asInteger( r_value ) ;
	obj = ( struct  rusage * )  R_getNativeReference(r_obj, "rusage", "rusagePtr") ;
	obj -> ru_maxrss = value ;
	return(r_obj);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rusagePtr_set_ru_ixrss (SEXP r_obj , SEXP r_value )
{
	struct  rusage *obj ;
	long int value ;
	value =  asInteger( r_value ) ;
	obj = ( struct  rusage * )  R_getNativeReference(r_obj, "rusage", "rusagePtr") ;
	obj -> ru_ixrss = value ;
	return(r_obj);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rusagePtr_set_ru_idrss (SEXP r_obj , SEXP r_value )
{
	struct  rusage *obj ;
	long int value ;
	value =  asInteger( r_value ) ;
	obj = ( struct  rusage * )  R_getNativeReference(r_obj, "rusage", "rusagePtr") ;
	obj -> ru_idrss = value ;
	return(r_obj);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rusagePtr_set_ru_isrss (SEXP r_obj , SEXP r_value )
{
	struct  rusage *obj ;
	long int value ;
	value =  asInteger( r_value ) ;
	obj = ( struct  rusage * )  R_getNativeReference(r_obj, "rusage", "rusagePtr") ;
	obj -> ru_isrss = value ;
	return(r_obj);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rusagePtr_set_ru_minflt (SEXP r_obj , SEXP r_value )
{
	struct  rusage *obj ;
	long int value ;
	value =  asInteger( r_value ) ;
	obj = ( struct  rusage * )  R_getNativeReference(r_obj, "rusage", "rusagePtr") ;
	obj -> ru_minflt = value ;
	return(r_obj);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rusagePtr_set_ru_majflt (SEXP r_obj , SEXP r_value )
{
	struct  rusage *obj ;
	long int value ;
	value =  asInteger( r_value ) ;
	obj = ( struct  rusage * )  R_getNativeReference(r_obj, "rusage", "rusagePtr") ;
	obj -> ru_majflt = value ;
	return(r_obj);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rusagePtr_set_ru_nswap (SEXP r_obj , SEXP r_value )
{
	struct  rusage *obj ;
	long int value ;
	value =  asInteger( r_value ) ;
	obj = ( struct  rusage * )  R_getNativeReference(r_obj, "rusage", "rusagePtr") ;
	obj -> ru_nswap = value ;
	return(r_obj);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rusagePtr_set_ru_inblock (SEXP r_obj , SEXP r_value )
{
	struct  rusage *obj ;
	long int value ;
	value =  asInteger( r_value ) ;
	obj = ( struct  rusage * )  R_getNativeReference(r_obj, "rusage", "rusagePtr") ;
	obj -> ru_inblock = value ;
	return(r_obj);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rusagePtr_set_ru_oublock (SEXP r_obj , SEXP r_value )
{
	struct  rusage *obj ;
	long int value ;
	value =  asInteger( r_value ) ;
	obj = ( struct  rusage * )  R_getNativeReference(r_obj, "rusage", "rusagePtr") ;
	obj -> ru_oublock = value ;
	return(r_obj);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rusagePtr_set_ru_msgsnd (SEXP r_obj , SEXP r_value )
{
	struct  rusage *obj ;
	long int value ;
	value =  asInteger( r_value ) ;
	obj = ( struct  rusage * )  R_getNativeReference(r_obj, "rusage", "rusagePtr") ;
	obj -> ru_msgsnd = value ;
	return(r_obj);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rusagePtr_set_ru_msgrcv (SEXP r_obj , SEXP r_value )
{
	struct  rusage *obj ;
	long int value ;
	value =  asInteger( r_value ) ;
	obj = ( struct  rusage * )  R_getNativeReference(r_obj, "rusage", "rusagePtr") ;
	obj -> ru_msgrcv = value ;
	return(r_obj);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rusagePtr_set_ru_nsignals (SEXP r_obj , SEXP r_value )
{
	struct  rusage *obj ;
	long int value ;
	value =  asInteger( r_value ) ;
	obj = ( struct  rusage * )  R_getNativeReference(r_obj, "rusage", "rusagePtr") ;
	obj -> ru_nsignals = value ;
	return(r_obj);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rusagePtr_set_ru_nvcsw (SEXP r_obj , SEXP r_value )
{
	struct  rusage *obj ;
	long int value ;
	value =  asInteger( r_value ) ;
	obj = ( struct  rusage * )  R_getNativeReference(r_obj, "rusage", "rusagePtr") ;
	obj -> ru_nvcsw = value ;
	return(r_obj);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_rusagePtr_set_ru_nivcsw (SEXP r_obj , SEXP r_value )
{
	struct  rusage *obj ;
	long int value ;
	value =  asInteger( r_value ) ;
	obj = ( struct  rusage * )  R_getNativeReference(r_obj, "rusage", "rusagePtr") ;
	obj -> ru_nivcsw = value ;
	return(r_obj);
} 
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_coerce_rusage_rusagePtr ( SEXP r_from )
{
	struct  rusage * ans ;
	
	SEXP tmp;
	
	ans = ( struct  rusage * ) malloc( sizeof( struct  rusage ));
	tmp = GET_SLOT(r_from, Rf_install("ru_utime"));
	ans->ru_utime = DEREF_REF( tmp ,  struct  timeval ) ;
	tmp = GET_SLOT(r_from, Rf_install("ru_stime"));
	ans->ru_stime = DEREF_REF( tmp ,  struct  timeval ) ;
	tmp = GET_SLOT(r_from, Rf_install("ru_maxrss"));
	ans->ru_maxrss = asInteger( tmp ) ;
	tmp = GET_SLOT(r_from, Rf_install("ru_ixrss"));
	ans->ru_ixrss = asInteger( tmp ) ;
	tmp = GET_SLOT(r_from, Rf_install("ru_idrss"));
	ans->ru_idrss = asInteger( tmp ) ;
	tmp = GET_SLOT(r_from, Rf_install("ru_isrss"));
	ans->ru_isrss = asInteger( tmp ) ;
	tmp = GET_SLOT(r_from, Rf_install("ru_minflt"));
	ans->ru_minflt = asInteger( tmp ) ;
	tmp = GET_SLOT(r_from, Rf_install("ru_majflt"));
	ans->ru_majflt = asInteger( tmp ) ;
	tmp = GET_SLOT(r_from, Rf_install("ru_nswap"));
	ans->ru_nswap = asInteger( tmp ) ;
	tmp = GET_SLOT(r_from, Rf_install("ru_inblock"));
	ans->ru_inblock = asInteger( tmp ) ;
	tmp = GET_SLOT(r_from, Rf_install("ru_oublock"));
	ans->ru_oublock = asInteger( tmp ) ;
	tmp = GET_SLOT(r_from, Rf_install("ru_msgsnd"));
	ans->ru_msgsnd = asInteger( tmp ) ;
	tmp = GET_SLOT(r_from, Rf_install("ru_msgrcv"));
	ans->ru_msgrcv = asInteger( tmp ) ;
	tmp = GET_SLOT(r_from, Rf_install("ru_nsignals"));
	ans->ru_nsignals = asInteger( tmp ) ;
	tmp = GET_SLOT(r_from, Rf_install("ru_nvcsw"));
	ans->ru_nvcsw = asInteger( tmp ) ;
	tmp = GET_SLOT(r_from, Rf_install("ru_nivcsw"));
	ans->ru_nivcsw = asInteger( tmp ) ;
	
	return ( R_createNativeReference( (void *)  ans ,  "rusagePtr" , "rusagePtr" ) );
}
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_coerce_rusagePtr_rusage ( SEXP from )
{
	struct  rusage * ans ;
	ans = (struct  rusage *) R_getNativeReference(from, "rusage", "rusagePtr");
	return( R_copyStruct_rusage ( ans ) );
} 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_new_rusage ()
{
	SEXP r_ans = R_NilValue;
	struct  rusage * ans;
	
	ans = ( struct  rusage *) calloc (1, sizeof( struct  rusage ));
	 r_ans =  R_createNativeReference( (void *)  ans ,  "rusagePtr" , "rusagePtr" ) ;
	return(r_ans);
} 
#ifdef __cplusplus
extern "C"
#endif
void
R_free_rusage_finalizer (SEXP val)
{
	struct  rusage * ans = NULL;
	ans = ( struct  rusage * ) R_ExternalPtrAddr(val);
	 if(ans) { fprintf(stderr, "freeing rusage \n"); free(ans);}
} 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_free_rusage (SEXP val)
{
	struct  rusage * ans = NULL;
	ans =  (struct  rusage *) R_getNativeReference(val, "rusagePtr", "rusagePtr") ;
	
	 if(ans) { fprintf(stderr, "freeing rusage \n"); free(ans);}
	return(ScalarLogical(ans ? TRUE : FALSE));
} 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_select(SEXP r_r2590, SEXP r_r2599, SEXP r_r2610, SEXP r_r2623, SEXP r_r2641, SEXP r__copy, SEXP r_resultLength)
{
	
		SEXP r_ans = R_NilValue;
		SEXP r_names = R_NilValue;
		int r_ctr = 0;
		fd_set r2599, *_p_r2599 = &r2599;
		fd_set r2610, *_p_r2610 = &r2610;
		fd_set r2623, *_p_r2623 = &r2623;
		struct  timeval r2641, *_p_r2641 = &r2641;
		int r2590 ;
		 int ans ;
	
		 r2590  =  asInteger( r_r2590 ) ;
		 if(GET_LENGTH( r_r2599 ) > 0)  {
		 	_p_r2599  =  (fd_set *) R_getNativeReference(r_r2599, "fd_setPtr", "fd_setPtr") ;
		 		}
		 if(GET_LENGTH( r_r2610 ) > 0)  {
		 	_p_r2610  =  (fd_set *) R_getNativeReference(r_r2610, "fd_setPtr", "fd_setPtr") ;
		 		}
		 if(GET_LENGTH( r_r2623 ) > 0)  {
		 	_p_r2623  =  (fd_set *) R_getNativeReference(r_r2623, "fd_setPtr", "fd_setPtr") ;
		 		}
		 if(GET_LENGTH( r_r2641 ) > 0)  {
		 	_p_r2641  =  (struct  timeval *) R_getNativeReference(r_r2641, "timevalPtr", "timevalPtr") ;
		 		}
	
		ans =  select ( r2590, _p_r2599, _p_r2610, _p_r2623, _p_r2641 );
		 PROTECT(r_ans = NEW_LIST( INTEGER(r_resultLength)[0]));
	 PROTECT(r_names = NEW_CHARACTER( INTEGER(r_resultLength)[0]));
	 SET_VECTOR_ELT(r_ans, 0,  ScalarInteger ( ans ) );
	 SET_STRING_ELT(r_names, 0, mkChar(".result"));
	 r_ctr++;
	 
	 if( LOGICAL(r__copy)[ 0 ]  != NA_LOGICAL) {
	 	 if( LOGICAL(r__copy)[ 0 ]  == FALSE && GET_LENGTH( r_r2599 ) == 0) {
	 	 	 PROBLEM "ignoring request to not copy argument r2599 as only local/stack value is available"
	 	 	 WARN;
	 	 }
	 	 SET_VECTOR_ELT( r_ans, r_ctr, LOGICAL(r__copy)[ 0 ] == FALSE && GET_LENGTH( r_r2599 ) > 0 ?  r_r2599 : R_copyStruct_fd_set( &*_p_r2599 ) );
	 	SET_STRING_ELT( r_names, r_ctr++, mkChar("r2599"));
	 }
	 
	 if( LOGICAL(r__copy)[ 1 ]  != NA_LOGICAL) {
	 	 if( LOGICAL(r__copy)[ 1 ]  == FALSE && GET_LENGTH( r_r2610 ) == 0) {
	 	 	 PROBLEM "ignoring request to not copy argument r2610 as only local/stack value is available"
	 	 	 WARN;
	 	 }
	 	 SET_VECTOR_ELT( r_ans, r_ctr, LOGICAL(r__copy)[ 1 ] == FALSE && GET_LENGTH( r_r2610 ) > 0 ?  r_r2610 : R_copyStruct_fd_set( &*_p_r2610 ) );
	 	SET_STRING_ELT( r_names, r_ctr++, mkChar("r2610"));
	 }
	 
	 if( LOGICAL(r__copy)[ 2 ]  != NA_LOGICAL) {
	 	 if( LOGICAL(r__copy)[ 2 ]  == FALSE && GET_LENGTH( r_r2623 ) == 0) {
	 	 	 PROBLEM "ignoring request to not copy argument r2623 as only local/stack value is available"
	 	 	 WARN;
	 	 }
	 	 SET_VECTOR_ELT( r_ans, r_ctr, LOGICAL(r__copy)[ 2 ] == FALSE && GET_LENGTH( r_r2623 ) > 0 ?  r_r2623 : R_copyStruct_fd_set( &*_p_r2623 ) );
	 	SET_STRING_ELT( r_names, r_ctr++, mkChar("r2623"));
	 }
	 
	 if( LOGICAL(r__copy)[ 3 ]  != NA_LOGICAL) {
	 	 if( LOGICAL(r__copy)[ 3 ]  == FALSE && GET_LENGTH( r_r2641 ) == 0) {
	 	 	 PROBLEM "ignoring request to not copy argument r2641 as only local/stack value is available"
	 	 	 WARN;
	 	 }
	 	 SET_VECTOR_ELT( r_ans, r_ctr, LOGICAL(r__copy)[ 3 ] == FALSE && GET_LENGTH( r_r2641 ) > 0 ?  r_r2641 : R_copyStruct_timeval( &*_p_r2641 ) );
	 	SET_STRING_ELT( r_names, r_ctr++, mkChar("r2641"));
	 }
	 
	 SET_NAMES(r_ans, r_names);
	 UNPROTECT(2);
	
		 return(r_ans);
}
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_pselect(SEXP r_r2600, SEXP r_r2611, SEXP r_r2624, SEXP r_r2642, SEXP r_r2661, SEXP r_r2683, SEXP r__copy, SEXP r_resultLength)
{
	
		SEXP r_ans = R_NilValue;
		SEXP r_names = R_NilValue;
		int r_ctr = 0;
		fd_set r2611, *_p_r2611 = &r2611;
		fd_set r2624, *_p_r2624 = &r2624;
		fd_set r2642, *_p_r2642 = &r2642;
		struct  timespec r2661, *_p_r2661 = &r2661;
		__sigset_t r2683, *_p_r2683 = &r2683;
		int r2600 ;
		 int ans ;
	
		 r2600  =  asInteger( r_r2600 ) ;
		 if(GET_LENGTH( r_r2611 ) > 0)  {
		 	_p_r2611  =  (fd_set *) R_getNativeReference(r_r2611, "fd_setPtr", "fd_setPtr") ;
		 		}
		 if(GET_LENGTH( r_r2624 ) > 0)  {
		 	_p_r2624  =  (fd_set *) R_getNativeReference(r_r2624, "fd_setPtr", "fd_setPtr") ;
		 		}
		 if(GET_LENGTH( r_r2642 ) > 0)  {
		 	_p_r2642  =  (fd_set *) R_getNativeReference(r_r2642, "fd_setPtr", "fd_setPtr") ;
		 		}
		 if(GET_LENGTH( r_r2661 ) > 0)  {
		 	_p_r2661  =  (struct  timespec *) R_getNativeReference(r_r2661, "timespecPtr", "timespecPtr") ;
		 		}
		 if(GET_LENGTH( r_r2683 ) > 0)  {
		 	_p_r2683  =  (__sigset_t *) R_getNativeReference(r_r2683, "__sigset_tPtr", "__sigset_tPtr") ;
		 		}
	
		ans =  pselect ( r2600, _p_r2611, _p_r2624, _p_r2642, _p_r2661, _p_r2683 );
		 PROTECT(r_ans = NEW_LIST( INTEGER(r_resultLength)[0]));
	 PROTECT(r_names = NEW_CHARACTER( INTEGER(r_resultLength)[0]));
	 SET_VECTOR_ELT(r_ans, 0,  ScalarInteger ( ans ) );
	 SET_STRING_ELT(r_names, 0, mkChar(".result"));
	 r_ctr++;
	 
	 if( LOGICAL(r__copy)[ 0 ]  != NA_LOGICAL) {
	 	 if( LOGICAL(r__copy)[ 0 ]  == FALSE && GET_LENGTH( r_r2611 ) == 0) {
	 	 	 PROBLEM "ignoring request to not copy argument r2611 as only local/stack value is available"
	 	 	 WARN;
	 	 }
	 	 SET_VECTOR_ELT( r_ans, r_ctr, LOGICAL(r__copy)[ 0 ] == FALSE && GET_LENGTH( r_r2611 ) > 0 ?  r_r2611 : R_copyStruct_fd_set( &*_p_r2611 ) );
	 	SET_STRING_ELT( r_names, r_ctr++, mkChar("r2611"));
	 }
	 
	 if( LOGICAL(r__copy)[ 1 ]  != NA_LOGICAL) {
	 	 if( LOGICAL(r__copy)[ 1 ]  == FALSE && GET_LENGTH( r_r2624 ) == 0) {
	 	 	 PROBLEM "ignoring request to not copy argument r2624 as only local/stack value is available"
	 	 	 WARN;
	 	 }
	 	 SET_VECTOR_ELT( r_ans, r_ctr, LOGICAL(r__copy)[ 1 ] == FALSE && GET_LENGTH( r_r2624 ) > 0 ?  r_r2624 : R_copyStruct_fd_set( &*_p_r2624 ) );
	 	SET_STRING_ELT( r_names, r_ctr++, mkChar("r2624"));
	 }
	 
	 if( LOGICAL(r__copy)[ 2 ]  != NA_LOGICAL) {
	 	 if( LOGICAL(r__copy)[ 2 ]  == FALSE && GET_LENGTH( r_r2642 ) == 0) {
	 	 	 PROBLEM "ignoring request to not copy argument r2642 as only local/stack value is available"
	 	 	 WARN;
	 	 }
	 	 SET_VECTOR_ELT( r_ans, r_ctr, LOGICAL(r__copy)[ 2 ] == FALSE && GET_LENGTH( r_r2642 ) > 0 ?  r_r2642 : R_copyStruct_fd_set( &*_p_r2642 ) );
	 	SET_STRING_ELT( r_names, r_ctr++, mkChar("r2642"));
	 }
	 
	 if( LOGICAL(r__copy)[ 3 ]  != NA_LOGICAL) {
	 	 if( LOGICAL(r__copy)[ 3 ]  == FALSE && GET_LENGTH( r_r2661 ) == 0) {
	 	 	 PROBLEM "ignoring request to not copy argument r2661 as only local/stack value is available"
	 	 	 WARN;
	 	 }
	 	 SET_VECTOR_ELT( r_ans, r_ctr, LOGICAL(r__copy)[ 3 ] == FALSE && GET_LENGTH( r_r2661 ) > 0 ?  r_r2661 : R_copyStruct_timespec( &*_p_r2661 ) );
	 	SET_STRING_ELT( r_names, r_ctr++, mkChar("r2661"));
	 }
	 
	 if( LOGICAL(r__copy)[ 4 ]  != NA_LOGICAL) {
	 	 if( LOGICAL(r__copy)[ 4 ]  == FALSE && GET_LENGTH( r_r2683 ) == 0) {
	 	 	 PROBLEM "ignoring request to not copy argument r2683 as only local/stack value is available"
	 	 	 WARN;
	 	 }
	 	 SET_VECTOR_ELT( r_ans, r_ctr, LOGICAL(r__copy)[ 4 ] == FALSE && GET_LENGTH( r_r2683 ) > 0 ?  r_r2683 : R_copyStruct___sigset_t( &*_p_r2683 ) );
	 	SET_STRING_ELT( r_names, r_ctr++, mkChar("r2683"));
	 }
	 
	 SET_NAMES(r_ans, r_names);
	 UNPROTECT(2);
	
		 return(r_ans);
}
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_gettimeofday(SEXP r_r2612, SEXP r_r2626, SEXP r__copy, SEXP r_resultLength)
{
	
		SEXP r_ans = R_NilValue;
		SEXP r_names = R_NilValue;
		int r_ctr = 0;
		struct  timeval r2612, *_p_r2612 = &r2612;
		struct  timezone r2626, *_p_r2626 = &r2626;
		
		 int ans ;
	
		 if(GET_LENGTH( r_r2612 ) > 0)  {
		 	_p_r2612  =  (struct  timeval *) R_getNativeReference(r_r2612, "timevalPtr", "timevalPtr") ;
		 		}
		 if(GET_LENGTH( r_r2626 ) > 0)  {
		 	_p_r2626  =  (struct  timezone *) R_getNativeReference(r_r2626, "timezonePtr", "timezonePtr") ;
		 		}
	
		ans =  gettimeofday ( _p_r2612, _p_r2626 );
		 PROTECT(r_ans = NEW_LIST( INTEGER(r_resultLength)[0]));
	 PROTECT(r_names = NEW_CHARACTER( INTEGER(r_resultLength)[0]));
	 SET_VECTOR_ELT(r_ans, 0,  ScalarInteger ( ans ) );
	 SET_STRING_ELT(r_names, 0, mkChar(".result"));
	 r_ctr++;
	 
	 if( LOGICAL(r__copy)[ 0 ]  != NA_LOGICAL) {
	 	 if( LOGICAL(r__copy)[ 0 ]  == FALSE && GET_LENGTH( r_r2612 ) == 0) {
	 	 	 PROBLEM "ignoring request to not copy argument r2612 as only local/stack value is available"
	 	 	 WARN;
	 	 }
	 	 SET_VECTOR_ELT( r_ans, r_ctr, LOGICAL(r__copy)[ 0 ] == FALSE && GET_LENGTH( r_r2612 ) > 0 ?  r_r2612 : R_copyStruct_timeval( &*_p_r2612 ) );
	 	SET_STRING_ELT( r_names, r_ctr++, mkChar("r2612"));
	 }
	 
	 if( LOGICAL(r__copy)[ 1 ]  != NA_LOGICAL) {
	 	 if( LOGICAL(r__copy)[ 1 ]  == FALSE && GET_LENGTH( r_r2626 ) == 0) {
	 	 	 PROBLEM "ignoring request to not copy argument r2626 as only local/stack value is available"
	 	 	 WARN;
	 	 }
	 	 SET_VECTOR_ELT( r_ans, r_ctr, LOGICAL(r__copy)[ 1 ] == FALSE && GET_LENGTH( r_r2626 ) > 0 ?  r_r2626 : R_copyStruct_timezone( &*_p_r2626 ) );
	 	SET_STRING_ELT( r_names, r_ctr++, mkChar("r2626"));
	 }
	 
	 SET_NAMES(r_ans, r_names);
	 UNPROTECT(2);
	
		 return(r_ans);
}
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_settimeofday(SEXP r_r2627, SEXP r_r2647, SEXP r__copy, SEXP r_resultLength)
{
	
		SEXP r_ans = R_NilValue;
		SEXP r_names = R_NilValue;
		int r_ctr = 0;
		struct  timeval r2627, *_p_r2627 = &r2627;
		struct  timezone r2647, *_p_r2647 = &r2647;
		
		 int ans ;
	
		 if(GET_LENGTH( r_r2627 ) > 0)  {
		 	_p_r2627  =  (struct  timeval *) R_getNativeReference(r_r2627, "timevalPtr", "timevalPtr") ;
		 		}
		 if(GET_LENGTH( r_r2647 ) > 0)  {
		 	_p_r2647  =  (struct  timezone *) R_getNativeReference(r_r2647, "timezonePtr", "timezonePtr") ;
		 		}
	
		ans =  settimeofday ( _p_r2627, _p_r2647 );
		 PROTECT(r_ans = NEW_LIST( INTEGER(r_resultLength)[0]));
	 PROTECT(r_names = NEW_CHARACTER( INTEGER(r_resultLength)[0]));
	 SET_VECTOR_ELT(r_ans, 0,  ScalarInteger ( ans ) );
	 SET_STRING_ELT(r_names, 0, mkChar(".result"));
	 r_ctr++;
	 
	 if( LOGICAL(r__copy)[ 0 ]  != NA_LOGICAL) {
	 	 if( LOGICAL(r__copy)[ 0 ]  == FALSE && GET_LENGTH( r_r2627 ) == 0) {
	 	 	 PROBLEM "ignoring request to not copy argument r2627 as only local/stack value is available"
	 	 	 WARN;
	 	 }
	 	 SET_VECTOR_ELT( r_ans, r_ctr, LOGICAL(r__copy)[ 0 ] == FALSE && GET_LENGTH( r_r2627 ) > 0 ?  r_r2627 : R_copyStruct_timeval( &*_p_r2627 ) );
	 	SET_STRING_ELT( r_names, r_ctr++, mkChar("r2627"));
	 }
	 
	 if( LOGICAL(r__copy)[ 1 ]  != NA_LOGICAL) {
	 	 if( LOGICAL(r__copy)[ 1 ]  == FALSE && GET_LENGTH( r_r2647 ) == 0) {
	 	 	 PROBLEM "ignoring request to not copy argument r2647 as only local/stack value is available"
	 	 	 WARN;
	 	 }
	 	 SET_VECTOR_ELT( r_ans, r_ctr, LOGICAL(r__copy)[ 1 ] == FALSE && GET_LENGTH( r_r2647 ) > 0 ?  r_r2647 : R_copyStruct_timezone( &*_p_r2647 ) );
	 	SET_STRING_ELT( r_names, r_ctr++, mkChar("r2647"));
	 }
	 
	 SET_NAMES(r_ans, r_names);
	 UNPROTECT(2);
	
		 return(r_ans);
}
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_adjtime(SEXP r_r2648, SEXP r_r2668, SEXP r__copy, SEXP r_resultLength)
{
	
		SEXP r_ans = R_NilValue;
		SEXP r_names = R_NilValue;
		int r_ctr = 0;
		struct  timeval r2648, *_p_r2648 = &r2648;
		struct  timeval r2668, *_p_r2668 = &r2668;
		
		 int ans ;
	
		 if(GET_LENGTH( r_r2648 ) > 0)  {
		 	_p_r2648  =  (struct  timeval *) R_getNativeReference(r_r2648, "timevalPtr", "timevalPtr") ;
		 		}
		 if(GET_LENGTH( r_r2668 ) > 0)  {
		 	_p_r2668  =  (struct  timeval *) R_getNativeReference(r_r2668, "timevalPtr", "timevalPtr") ;
		 		}
	
		ans =  adjtime ( _p_r2648, _p_r2668 );
		 PROTECT(r_ans = NEW_LIST( INTEGER(r_resultLength)[0]));
	 PROTECT(r_names = NEW_CHARACTER( INTEGER(r_resultLength)[0]));
	 SET_VECTOR_ELT(r_ans, 0,  ScalarInteger ( ans ) );
	 SET_STRING_ELT(r_names, 0, mkChar(".result"));
	 r_ctr++;
	 
	 if( LOGICAL(r__copy)[ 0 ]  != NA_LOGICAL) {
	 	 if( LOGICAL(r__copy)[ 0 ]  == FALSE && GET_LENGTH( r_r2648 ) == 0) {
	 	 	 PROBLEM "ignoring request to not copy argument r2648 as only local/stack value is available"
	 	 	 WARN;
	 	 }
	 	 SET_VECTOR_ELT( r_ans, r_ctr, LOGICAL(r__copy)[ 0 ] == FALSE && GET_LENGTH( r_r2648 ) > 0 ?  r_r2648 : R_copyStruct_timeval( &*_p_r2648 ) );
	 	SET_STRING_ELT( r_names, r_ctr++, mkChar("r2648"));
	 }
	 
	 if( LOGICAL(r__copy)[ 1 ]  != NA_LOGICAL) {
	 	 if( LOGICAL(r__copy)[ 1 ]  == FALSE && GET_LENGTH( r_r2668 ) == 0) {
	 	 	 PROBLEM "ignoring request to not copy argument r2668 as only local/stack value is available"
	 	 	 WARN;
	 	 }
	 	 SET_VECTOR_ELT( r_ans, r_ctr, LOGICAL(r__copy)[ 1 ] == FALSE && GET_LENGTH( r_r2668 ) > 0 ?  r_r2668 : R_copyStruct_timeval( &*_p_r2668 ) );
	 	SET_STRING_ELT( r_names, r_ctr++, mkChar("r2668"));
	 }
	 
	 SET_NAMES(r_ans, r_names);
	 UNPROTECT(2);
	
		 return(r_ans);
}
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_getitimer(SEXP r_r2669, SEXP r_r2691, SEXP r__copy, SEXP r_resultLength)
{
	
		SEXP r_ans = R_NilValue;
		SEXP r_names = R_NilValue;
		int r_ctr = 0;
		struct  itimerval r2691, *_p_r2691 = &r2691;
		__itimer_which_t r2669 ;
		 int ans ;
	
		 r2669  =  asInteger( r_r2669 ) ;
		 if(GET_LENGTH( r_r2691 ) > 0)  {
		 	_p_r2691  =  (struct  itimerval *) R_getNativeReference(r_r2691, "itimervalPtr", "itimervalPtr") ;
		 		}
	
		ans =  getitimer ( r2669, _p_r2691 );
		 PROTECT(r_ans = NEW_LIST( INTEGER(r_resultLength)[0]));
	 PROTECT(r_names = NEW_CHARACTER( INTEGER(r_resultLength)[0]));
	 SET_VECTOR_ELT(r_ans, 0,  ScalarInteger ( ans ) );
	 SET_STRING_ELT(r_names, 0, mkChar(".result"));
	 r_ctr++;
	 
	 if( LOGICAL(r__copy)[ 0 ]  != NA_LOGICAL) {
	 	 if( LOGICAL(r__copy)[ 0 ]  == FALSE && GET_LENGTH( r_r2691 ) == 0) {
	 	 	 PROBLEM "ignoring request to not copy argument r2691 as only local/stack value is available"
	 	 	 WARN;
	 	 }
	 	 SET_VECTOR_ELT( r_ans, r_ctr, LOGICAL(r__copy)[ 0 ] == FALSE && GET_LENGTH( r_r2691 ) > 0 ?  r_r2691 : R_copyStruct_itimerval( &*_p_r2691 ) );
	 	SET_STRING_ELT( r_names, r_ctr++, mkChar("r2691"));
	 }
	 
	 SET_NAMES(r_ans, r_names);
	 UNPROTECT(2);
	
		 return(r_ans);
}
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_setitimer(SEXP r_r2692, SEXP r_r2713, SEXP r_r2738, SEXP r__copy, SEXP r_resultLength)
{
	
		SEXP r_ans = R_NilValue;
		SEXP r_names = R_NilValue;
		int r_ctr = 0;
		struct  itimerval r2713, *_p_r2713 = &r2713;
		struct  itimerval r2738, *_p_r2738 = &r2738;
		__itimer_which_t r2692 ;
		 int ans ;
	
		 r2692  =  asInteger( r_r2692 ) ;
		 if(GET_LENGTH( r_r2713 ) > 0)  {
		 	_p_r2713  =  (struct  itimerval *) R_getNativeReference(r_r2713, "itimervalPtr", "itimervalPtr") ;
		 		}
		 if(GET_LENGTH( r_r2738 ) > 0)  {
		 	_p_r2738  =  (struct  itimerval *) R_getNativeReference(r_r2738, "itimervalPtr", "itimervalPtr") ;
		 		}
	
		ans =  setitimer ( r2692, _p_r2713, _p_r2738 );
		 PROTECT(r_ans = NEW_LIST( INTEGER(r_resultLength)[0]));
	 PROTECT(r_names = NEW_CHARACTER( INTEGER(r_resultLength)[0]));
	 SET_VECTOR_ELT(r_ans, 0,  ScalarInteger ( ans ) );
	 SET_STRING_ELT(r_names, 0, mkChar(".result"));
	 r_ctr++;
	 
	 if( LOGICAL(r__copy)[ 0 ]  != NA_LOGICAL) {
	 	 if( LOGICAL(r__copy)[ 0 ]  == FALSE && GET_LENGTH( r_r2713 ) == 0) {
	 	 	 PROBLEM "ignoring request to not copy argument r2713 as only local/stack value is available"
	 	 	 WARN;
	 	 }
	 	 SET_VECTOR_ELT( r_ans, r_ctr, LOGICAL(r__copy)[ 0 ] == FALSE && GET_LENGTH( r_r2713 ) > 0 ?  r_r2713 : R_copyStruct_itimerval( &*_p_r2713 ) );
	 	SET_STRING_ELT( r_names, r_ctr++, mkChar("r2713"));
	 }
	 
	 if( LOGICAL(r__copy)[ 1 ]  != NA_LOGICAL) {
	 	 if( LOGICAL(r__copy)[ 1 ]  == FALSE && GET_LENGTH( r_r2738 ) == 0) {
	 	 	 PROBLEM "ignoring request to not copy argument r2738 as only local/stack value is available"
	 	 	 WARN;
	 	 }
	 	 SET_VECTOR_ELT( r_ans, r_ctr, LOGICAL(r__copy)[ 1 ] == FALSE && GET_LENGTH( r_r2738 ) > 0 ?  r_r2738 : R_copyStruct_itimerval( &*_p_r2738 ) );
	 	SET_STRING_ELT( r_names, r_ctr++, mkChar("r2738"));
	 }
	 
	 SET_NAMES(r_ans, r_names);
	 UNPROTECT(2);
	
		 return(r_ans);
}
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_utimes(SEXP r_r2714, SEXP r_r2739, SEXP r__copy, SEXP r_resultLength)
{
	
		SEXP r_ans = R_NilValue;
		SEXP r_names = R_NilValue;
		int r_ctr = 0;
		struct  timeval r2739, *_p_r2739 = &r2739;
		const const char * r2714 ;
		 int ans ;
	
		 r2714  =  GET_LENGTH( r_r2714 ) > 0 ? CHAR(STRING_ELT( r_r2714 , 0)) :  NULL ;
		 if(GET_LENGTH( r_r2739 ) > 0)  {
		 	_p_r2739  =  (struct  timeval *) R_getNativeReference(r_r2739, "timevalPtr", "timevalPtr") ;
		 		}
	
		ans =  utimes ( r2714, _p_r2739 );
		 PROTECT(r_ans = NEW_LIST( INTEGER(r_resultLength)[0]));
	 PROTECT(r_names = NEW_CHARACTER( INTEGER(r_resultLength)[0]));
	 SET_VECTOR_ELT(r_ans, 0,  ScalarInteger ( ans ) );
	 SET_STRING_ELT(r_names, 0, mkChar(".result"));
	 r_ctr++;
	 
	 if( LOGICAL(r__copy)[ 0 ]  != NA_LOGICAL) {
	 	 if( LOGICAL(r__copy)[ 0 ]  == FALSE && GET_LENGTH( r_r2739 ) == 0) {
	 	 	 PROBLEM "ignoring request to not copy argument r2739 as only local/stack value is available"
	 	 	 WARN;
	 	 }
	 	 SET_VECTOR_ELT( r_ans, r_ctr, LOGICAL(r__copy)[ 0 ] == FALSE && GET_LENGTH( r_r2739 ) > 0 ?  r_r2739 : R_copyStruct_timeval( &*_p_r2739 ) );
	 	SET_STRING_ELT( r_names, r_ctr++, mkChar("r2739"));
	 }
	 
	 SET_NAMES(r_ans, r_names);
	 UNPROTECT(2);
	
		 return(r_ans);
}
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_lutimes(SEXP r_r2714, SEXP r_r2739, SEXP r__copy, SEXP r_resultLength)
{
	
		SEXP r_ans = R_NilValue;
		SEXP r_names = R_NilValue;
		int r_ctr = 0;
		struct  timeval r2739, *_p_r2739 = &r2739;
		const const char * r2714 ;
		 int ans ;
	
		 r2714  =  GET_LENGTH( r_r2714 ) > 0 ? CHAR(STRING_ELT( r_r2714 , 0)) :  NULL ;
		 if(GET_LENGTH( r_r2739 ) > 0)  {
		 	_p_r2739  =  (struct  timeval *) R_getNativeReference(r_r2739, "timevalPtr", "timevalPtr") ;
		 		}
	
		ans =  lutimes ( r2714, _p_r2739 );
		 PROTECT(r_ans = NEW_LIST( INTEGER(r_resultLength)[0]));
	 PROTECT(r_names = NEW_CHARACTER( INTEGER(r_resultLength)[0]));
	 SET_VECTOR_ELT(r_ans, 0,  ScalarInteger ( ans ) );
	 SET_STRING_ELT(r_names, 0, mkChar(".result"));
	 r_ctr++;
	 
	 if( LOGICAL(r__copy)[ 0 ]  != NA_LOGICAL) {
	 	 if( LOGICAL(r__copy)[ 0 ]  == FALSE && GET_LENGTH( r_r2739 ) == 0) {
	 	 	 PROBLEM "ignoring request to not copy argument r2739 as only local/stack value is available"
	 	 	 WARN;
	 	 }
	 	 SET_VECTOR_ELT( r_ans, r_ctr, LOGICAL(r__copy)[ 0 ] == FALSE && GET_LENGTH( r_r2739 ) > 0 ?  r_r2739 : R_copyStruct_timeval( &*_p_r2739 ) );
	 	SET_STRING_ELT( r_names, r_ctr++, mkChar("r2739"));
	 }
	 
	 SET_NAMES(r_ans, r_names);
	 UNPROTECT(2);
	
		 return(r_ans);
}
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_futimes(SEXP r_r2763, SEXP r_r2789, SEXP r__copy, SEXP r_resultLength)
{
	
		SEXP r_ans = R_NilValue;
		SEXP r_names = R_NilValue;
		int r_ctr = 0;
		struct  timeval r2789, *_p_r2789 = &r2789;
		int r2763 ;
		 int ans ;
	
		 r2763  =  asInteger( r_r2763 ) ;
		 if(GET_LENGTH( r_r2789 ) > 0)  {
		 	_p_r2789  =  (struct  timeval *) R_getNativeReference(r_r2789, "timevalPtr", "timevalPtr") ;
		 		}
	
		ans =  futimes ( r2763, _p_r2789 );
		 PROTECT(r_ans = NEW_LIST( INTEGER(r_resultLength)[0]));
	 PROTECT(r_names = NEW_CHARACTER( INTEGER(r_resultLength)[0]));
	 SET_VECTOR_ELT(r_ans, 0,  ScalarInteger ( ans ) );
	 SET_STRING_ELT(r_names, 0, mkChar(".result"));
	 r_ctr++;
	 
	 if( LOGICAL(r__copy)[ 0 ]  != NA_LOGICAL) {
	 	 if( LOGICAL(r__copy)[ 0 ]  == FALSE && GET_LENGTH( r_r2789 ) == 0) {
	 	 	 PROBLEM "ignoring request to not copy argument r2789 as only local/stack value is available"
	 	 	 WARN;
	 	 }
	 	 SET_VECTOR_ELT( r_ans, r_ctr, LOGICAL(r__copy)[ 0 ] == FALSE && GET_LENGTH( r_r2789 ) > 0 ?  r_r2789 : R_copyStruct_timeval( &*_p_r2789 ) );
	 	SET_STRING_ELT( r_names, r_ctr++, mkChar("r2789"));
	 }
	 
	 SET_NAMES(r_ans, r_names);
	 UNPROTECT(2);
	
		 return(r_ans);
}
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_getrlimit(SEXP r_r2790, SEXP r_r2812, SEXP r__copy, SEXP r_resultLength)
{
	
		SEXP r_ans = R_NilValue;
		SEXP r_names = R_NilValue;
		int r_ctr = 0;
		struct  rlimit r2812, *_p_r2812 = &r2812;
		__rlimit_resource_t r2790 ;
		 int ans ;
	
		 r2790  =  asInteger( r_r2790 ) ;
		 if(GET_LENGTH( r_r2812 ) > 0)  {
		 	_p_r2812  =  (struct  rlimit *) R_getNativeReference(r_r2812, "rlimitPtr", "rlimitPtr") ;
		 		}
	
		ans =  getrlimit ( r2790, _p_r2812 );
		 PROTECT(r_ans = NEW_LIST( INTEGER(r_resultLength)[0]));
	 PROTECT(r_names = NEW_CHARACTER( INTEGER(r_resultLength)[0]));
	 SET_VECTOR_ELT(r_ans, 0,  ScalarInteger ( ans ) );
	 SET_STRING_ELT(r_names, 0, mkChar(".result"));
	 r_ctr++;
	 
	 if( LOGICAL(r__copy)[ 0 ]  != NA_LOGICAL) {
	 	 if( LOGICAL(r__copy)[ 0 ]  == FALSE && GET_LENGTH( r_r2812 ) == 0) {
	 	 	 PROBLEM "ignoring request to not copy argument r2812 as only local/stack value is available"
	 	 	 WARN;
	 	 }
	 	 SET_VECTOR_ELT( r_ans, r_ctr, LOGICAL(r__copy)[ 0 ] == FALSE && GET_LENGTH( r_r2812 ) > 0 ?  r_r2812 : R_copyStruct_rlimit( &*_p_r2812 ) );
	 	SET_STRING_ELT( r_names, r_ctr++, mkChar("r2812"));
	 }
	 
	 SET_NAMES(r_ans, r_names);
	 UNPROTECT(2);
	
		 return(r_ans);
}
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_setrlimit(SEXP r_r2813, SEXP r_r2833, SEXP r__copy, SEXP r_resultLength)
{
	
		SEXP r_ans = R_NilValue;
		SEXP r_names = R_NilValue;
		int r_ctr = 0;
		struct  rlimit r2833, *_p_r2833 = &r2833;
		__rlimit_resource_t r2813 ;
		 int ans ;
	
		 r2813  =  asInteger( r_r2813 ) ;
		 if(GET_LENGTH( r_r2833 ) > 0)  {
		 	_p_r2833  =  (struct  rlimit *) R_getNativeReference(r_r2833, "rlimitPtr", "rlimitPtr") ;
		 		}
	
		ans =  setrlimit ( r2813, _p_r2833 );
		 PROTECT(r_ans = NEW_LIST( INTEGER(r_resultLength)[0]));
	 PROTECT(r_names = NEW_CHARACTER( INTEGER(r_resultLength)[0]));
	 SET_VECTOR_ELT(r_ans, 0,  ScalarInteger ( ans ) );
	 SET_STRING_ELT(r_names, 0, mkChar(".result"));
	 r_ctr++;
	 
	 if( LOGICAL(r__copy)[ 0 ]  != NA_LOGICAL) {
	 	 if( LOGICAL(r__copy)[ 0 ]  == FALSE && GET_LENGTH( r_r2833 ) == 0) {
	 	 	 PROBLEM "ignoring request to not copy argument r2833 as only local/stack value is available"
	 	 	 WARN;
	 	 }
	 	 SET_VECTOR_ELT( r_ans, r_ctr, LOGICAL(r__copy)[ 0 ] == FALSE && GET_LENGTH( r_r2833 ) > 0 ?  r_r2833 : R_copyStruct_rlimit( &*_p_r2833 ) );
	 	SET_STRING_ELT( r_names, r_ctr++, mkChar("r2833"));
	 }
	 
	 SET_NAMES(r_ans, r_names);
	 UNPROTECT(2);
	
		 return(r_ans);
}
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_getrusage(SEXP r_r2834, SEXP r_r2854, SEXP r__copy, SEXP r_resultLength)
{
	
		SEXP r_ans = R_NilValue;
		SEXP r_names = R_NilValue;
		int r_ctr = 0;
		struct  rusage r2854, *_p_r2854 = &r2854;
		__rusage_who_t r2834 ;
		 int ans ;
	
		 r2834  =  asInteger( r_r2834 ) ;
		 if(GET_LENGTH( r_r2854 ) > 0)  {
		 	_p_r2854  =  (struct  rusage *) R_getNativeReference(r_r2854, "rusagePtr", "rusagePtr") ;
		 		}
	
		ans =  getrusage ( r2834, _p_r2854 );
		 PROTECT(r_ans = NEW_LIST( INTEGER(r_resultLength)[0]));
	 PROTECT(r_names = NEW_CHARACTER( INTEGER(r_resultLength)[0]));
	 SET_VECTOR_ELT(r_ans, 0,  ScalarInteger ( ans ) );
	 SET_STRING_ELT(r_names, 0, mkChar(".result"));
	 r_ctr++;
	 
	 if( LOGICAL(r__copy)[ 0 ]  != NA_LOGICAL) {
	 	 if( LOGICAL(r__copy)[ 0 ]  == FALSE && GET_LENGTH( r_r2854 ) == 0) {
	 	 	 PROBLEM "ignoring request to not copy argument r2854 as only local/stack value is available"
	 	 	 WARN;
	 	 }
	 	 SET_VECTOR_ELT( r_ans, r_ctr, LOGICAL(r__copy)[ 0 ] == FALSE && GET_LENGTH( r_r2854 ) > 0 ?  r_r2854 : R_copyStruct_rusage( &*_p_r2854 ) );
	 	SET_STRING_ELT( r_names, r_ctr++, mkChar("r2854"));
	 }
	 
	 SET_NAMES(r_ans, r_names);
	 UNPROTECT(2);
	
		 return(r_ans);
}
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_getpriority(SEXP r_r2855, SEXP r_r2874)
{
	
		SEXP r_ans = R_NilValue;
		__priority_which_t r2855 ;
		id_t r2874 ;
		 int ans ;
	
		 r2855  =  asInteger( r_r2855 ) ;
		 r2874  =  asInteger( r_r2874 ) ;
	
		ans =  getpriority ( r2855, r2874 );
		 r_ans =  ScalarInteger ( ans ) ;
	
		 return(r_ans);
}
 
#ifdef __cplusplus
extern "C"
#endif
SEXP
R_setpriority(SEXP r_r2875, SEXP r_r2891, SEXP r_r2907)
{
	
		SEXP r_ans = R_NilValue;
		__priority_which_t r2875 ;
		id_t r2891 ;
		int r2907 ;
		 int ans ;
	
		 r2875  =  asInteger( r_r2875 ) ;
		 r2891  =  asInteger( r_r2891 ) ;
		 r2907  =  asInteger( r_r2907 ) ;
	
		ans =  setpriority ( r2875, r2891, r2907 );
		 r_ans =  ScalarInteger ( ans ) ;
	
		 return(r_ans);
}
 
/* registration information for the C/C++ routines accessible by R */

#include <R_ext/Rdynload.h>

static const R_CallMethodDef CallEntries [] = {
    { "R_select" , (DL_FUNC) & R_select , 7 } ,
   { "R_pselect" , (DL_FUNC) & R_pselect , 8 } ,
   { "R_gettimeofday" , (DL_FUNC) & R_gettimeofday , 4 } ,
   { "R_settimeofday" , (DL_FUNC) & R_settimeofday , 4 } ,
   { "R_adjtime" , (DL_FUNC) & R_adjtime , 4 } ,
   { "R_getitimer" , (DL_FUNC) & R_getitimer , 4 } ,
   { "R_setitimer" , (DL_FUNC) & R_setitimer , 5 } ,
   { "R_utimes" , (DL_FUNC) & R_utimes , 4 } ,
   { "R_lutimes" , (DL_FUNC) & R_lutimes , 4 } ,
   { "R_futimes" , (DL_FUNC) & R_futimes , 4 } ,
   { "R_getrlimit" , (DL_FUNC) & R_getrlimit , 4 } ,
   { "R_setrlimit" , (DL_FUNC) & R_setrlimit , 4 } ,
   { "R_getrusage" , (DL_FUNC) & R_getrusage , 4 } ,
   { "R_getpriority" , (DL_FUNC) & R_getpriority , 2 } ,
   { "R_setpriority" , (DL_FUNC) & R_setpriority , 3 } ,
   { "R_coerce_fd_set_fd_setPtr" , (DL_FUNC) & R_coerce_fd_set_fd_setPtr , 1 } ,
   { "R_coerce_fd_setPtr_fd_set" , (DL_FUNC) & R_coerce_fd_setPtr_fd_set , 1 } ,
   { "R_fd_setPtr_get___fds_bits" , (DL_FUNC) & R_fd_setPtr_get___fds_bits , 1 } ,
   { "R_fd_setPtr_set___fds_bits" , (DL_FUNC) & R_fd_setPtr_set___fds_bits , 2 } ,
   { "R_free_fd_set_finalizer" , (DL_FUNC) & R_free_fd_set_finalizer , 1 } ,
   { "R_free_fd_set" , (DL_FUNC) & R_free_fd_set , 1 } ,
   { "R_new_fd_set" , (DL_FUNC) & R_new_fd_set , 0 } ,
   { "R_coerce_timeval_timevalPtr" , (DL_FUNC) & R_coerce_timeval_timevalPtr , 1 } ,
   { "R_coerce_timevalPtr_timeval" , (DL_FUNC) & R_coerce_timevalPtr_timeval , 1 } ,
   { "R_timevalPtr_get_tv_sec" , (DL_FUNC) & R_timevalPtr_get_tv_sec , 1 } ,
   { "R_timevalPtr_get_tv_usec" , (DL_FUNC) & R_timevalPtr_get_tv_usec , 1 } ,
   { "R_timevalPtr_set_tv_sec" , (DL_FUNC) & R_timevalPtr_set_tv_sec , 2 } ,
   { "R_timevalPtr_set_tv_usec" , (DL_FUNC) & R_timevalPtr_set_tv_usec , 2 } ,
   { "R_free_timeval_finalizer" , (DL_FUNC) & R_free_timeval_finalizer , 1 } ,
   { "R_free_timeval" , (DL_FUNC) & R_free_timeval , 1 } ,
   { "R_new_timeval" , (DL_FUNC) & R_new_timeval , 0 } ,
   { "R_coerce_timespec_timespecPtr" , (DL_FUNC) & R_coerce_timespec_timespecPtr , 1 } ,
   { "R_coerce_timespecPtr_timespec" , (DL_FUNC) & R_coerce_timespecPtr_timespec , 1 } ,
   { "R_timespecPtr_get_tv_sec" , (DL_FUNC) & R_timespecPtr_get_tv_sec , 1 } ,
   { "R_timespecPtr_get_tv_nsec" , (DL_FUNC) & R_timespecPtr_get_tv_nsec , 1 } ,
   { "R_timespecPtr_set_tv_sec" , (DL_FUNC) & R_timespecPtr_set_tv_sec , 2 } ,
   { "R_timespecPtr_set_tv_nsec" , (DL_FUNC) & R_timespecPtr_set_tv_nsec , 2 } ,
   { "R_free_timespec_finalizer" , (DL_FUNC) & R_free_timespec_finalizer , 1 } ,
   { "R_free_timespec" , (DL_FUNC) & R_free_timespec , 1 } ,
   { "R_new_timespec" , (DL_FUNC) & R_new_timespec , 0 } ,
   { "R_coerce___sigset_t___sigset_tPtr" , (DL_FUNC) & R_coerce___sigset_t___sigset_tPtr , 1 } ,
   { "R_coerce___sigset_tPtr___sigset_t" , (DL_FUNC) & R_coerce___sigset_tPtr___sigset_t , 1 } ,
   { "R___sigset_tPtr_get___val" , (DL_FUNC) & R___sigset_tPtr_get___val , 1 } ,
   { "R___sigset_tPtr_set___val" , (DL_FUNC) & R___sigset_tPtr_set___val , 2 } ,
   { "R_free___sigset_t_finalizer" , (DL_FUNC) & R_free___sigset_t_finalizer , 1 } ,
   { "R_free___sigset_t" , (DL_FUNC) & R_free___sigset_t , 1 } ,
   { "R_new___sigset_t" , (DL_FUNC) & R_new___sigset_t , 0 } ,
   { "R_coerce_timezone_timezonePtr" , (DL_FUNC) & R_coerce_timezone_timezonePtr , 1 } ,
   { "R_coerce_timezonePtr_timezone" , (DL_FUNC) & R_coerce_timezonePtr_timezone , 1 } ,
   { "R_timezonePtr_get_tz_minuteswest" , (DL_FUNC) & R_timezonePtr_get_tz_minuteswest , 1 } ,
   { "R_timezonePtr_get_tz_dsttime" , (DL_FUNC) & R_timezonePtr_get_tz_dsttime , 1 } ,
   { "R_timezonePtr_set_tz_minuteswest" , (DL_FUNC) & R_timezonePtr_set_tz_minuteswest , 2 } ,
   { "R_timezonePtr_set_tz_dsttime" , (DL_FUNC) & R_timezonePtr_set_tz_dsttime , 2 } ,
   { "R_free_timezone_finalizer" , (DL_FUNC) & R_free_timezone_finalizer , 1 } ,
   { "R_free_timezone" , (DL_FUNC) & R_free_timezone , 1 } ,
   { "R_new_timezone" , (DL_FUNC) & R_new_timezone , 0 } ,
   { "R_coerce_itimerval_itimervalPtr" , (DL_FUNC) & R_coerce_itimerval_itimervalPtr , 1 } ,
   { "R_coerce_itimervalPtr_itimerval" , (DL_FUNC) & R_coerce_itimervalPtr_itimerval , 1 } ,
   { "R_itimervalPtr_get_it_interval" , (DL_FUNC) & R_itimervalPtr_get_it_interval , 1 } ,
   { "R_itimervalPtr_get_it_value" , (DL_FUNC) & R_itimervalPtr_get_it_value , 1 } ,
   { "R_itimervalPtr_set_it_interval" , (DL_FUNC) & R_itimervalPtr_set_it_interval , 2 } ,
   { "R_itimervalPtr_set_it_value" , (DL_FUNC) & R_itimervalPtr_set_it_value , 2 } ,
   { "R_free_itimerval_finalizer" , (DL_FUNC) & R_free_itimerval_finalizer , 1 } ,
   { "R_free_itimerval" , (DL_FUNC) & R_free_itimerval , 1 } ,
   { "R_new_itimerval" , (DL_FUNC) & R_new_itimerval , 0 } ,
   { "R_coerce_rlimit_rlimitPtr" , (DL_FUNC) & R_coerce_rlimit_rlimitPtr , 1 } ,
   { "R_coerce_rlimitPtr_rlimit" , (DL_FUNC) & R_coerce_rlimitPtr_rlimit , 1 } ,
   { "R_rlimitPtr_get_rlim_cur" , (DL_FUNC) & R_rlimitPtr_get_rlim_cur , 1 } ,
   { "R_rlimitPtr_get_rlim_max" , (DL_FUNC) & R_rlimitPtr_get_rlim_max , 1 } ,
   { "R_rlimitPtr_set_rlim_cur" , (DL_FUNC) & R_rlimitPtr_set_rlim_cur , 2 } ,
   { "R_rlimitPtr_set_rlim_max" , (DL_FUNC) & R_rlimitPtr_set_rlim_max , 2 } ,
   { "R_free_rlimit_finalizer" , (DL_FUNC) & R_free_rlimit_finalizer , 1 } ,
   { "R_free_rlimit" , (DL_FUNC) & R_free_rlimit , 1 } ,
   { "R_new_rlimit" , (DL_FUNC) & R_new_rlimit , 0 } ,
   { "R_coerce_rusage_rusagePtr" , (DL_FUNC) & R_coerce_rusage_rusagePtr , 1 } ,
   { "R_coerce_rusagePtr_rusage" , (DL_FUNC) & R_coerce_rusagePtr_rusage , 1 } ,
   { "R_rusagePtr_get_ru_utime" , (DL_FUNC) & R_rusagePtr_get_ru_utime , 1 } ,
   { "R_rusagePtr_get_ru_stime" , (DL_FUNC) & R_rusagePtr_get_ru_stime , 1 } ,
   { "R_rusagePtr_get_ru_maxrss" , (DL_FUNC) & R_rusagePtr_get_ru_maxrss , 1 } ,
   { "R_rusagePtr_get_ru_ixrss" , (DL_FUNC) & R_rusagePtr_get_ru_ixrss , 1 } ,
   { "R_rusagePtr_get_ru_idrss" , (DL_FUNC) & R_rusagePtr_get_ru_idrss , 1 } ,
   { "R_rusagePtr_get_ru_isrss" , (DL_FUNC) & R_rusagePtr_get_ru_isrss , 1 } ,
   { "R_rusagePtr_get_ru_minflt" , (DL_FUNC) & R_rusagePtr_get_ru_minflt , 1 } ,
   { "R_rusagePtr_get_ru_majflt" , (DL_FUNC) & R_rusagePtr_get_ru_majflt , 1 } ,
   { "R_rusagePtr_get_ru_nswap" , (DL_FUNC) & R_rusagePtr_get_ru_nswap , 1 } ,
   { "R_rusagePtr_get_ru_inblock" , (DL_FUNC) & R_rusagePtr_get_ru_inblock , 1 } ,
   { "R_rusagePtr_get_ru_oublock" , (DL_FUNC) & R_rusagePtr_get_ru_oublock , 1 } ,
   { "R_rusagePtr_get_ru_msgsnd" , (DL_FUNC) & R_rusagePtr_get_ru_msgsnd , 1 } ,
   { "R_rusagePtr_get_ru_msgrcv" , (DL_FUNC) & R_rusagePtr_get_ru_msgrcv , 1 } ,
   { "R_rusagePtr_get_ru_nsignals" , (DL_FUNC) & R_rusagePtr_get_ru_nsignals , 1 } ,
   { "R_rusagePtr_get_ru_nvcsw" , (DL_FUNC) & R_rusagePtr_get_ru_nvcsw , 1 } ,
   { "R_rusagePtr_get_ru_nivcsw" , (DL_FUNC) & R_rusagePtr_get_ru_nivcsw , 1 } ,
   { "R_rusagePtr_set_ru_utime" , (DL_FUNC) & R_rusagePtr_set_ru_utime , 2 } ,
   { "R_rusagePtr_set_ru_stime" , (DL_FUNC) & R_rusagePtr_set_ru_stime , 2 } ,
   { "R_rusagePtr_set_ru_maxrss" , (DL_FUNC) & R_rusagePtr_set_ru_maxrss , 2 } ,
   { "R_rusagePtr_set_ru_ixrss" , (DL_FUNC) & R_rusagePtr_set_ru_ixrss , 2 } ,
   { "R_rusagePtr_set_ru_idrss" , (DL_FUNC) & R_rusagePtr_set_ru_idrss , 2 } ,
   { "R_rusagePtr_set_ru_isrss" , (DL_FUNC) & R_rusagePtr_set_ru_isrss , 2 } ,
   { "R_rusagePtr_set_ru_minflt" , (DL_FUNC) & R_rusagePtr_set_ru_minflt , 2 } ,
   { "R_rusagePtr_set_ru_majflt" , (DL_FUNC) & R_rusagePtr_set_ru_majflt , 2 } ,
   { "R_rusagePtr_set_ru_nswap" , (DL_FUNC) & R_rusagePtr_set_ru_nswap , 2 } ,
   { "R_rusagePtr_set_ru_inblock" , (DL_FUNC) & R_rusagePtr_set_ru_inblock , 2 } ,
   { "R_rusagePtr_set_ru_oublock" , (DL_FUNC) & R_rusagePtr_set_ru_oublock , 2 } ,
   { "R_rusagePtr_set_ru_msgsnd" , (DL_FUNC) & R_rusagePtr_set_ru_msgsnd , 2 } ,
   { "R_rusagePtr_set_ru_msgrcv" , (DL_FUNC) & R_rusagePtr_set_ru_msgrcv , 2 } ,
   { "R_rusagePtr_set_ru_nsignals" , (DL_FUNC) & R_rusagePtr_set_ru_nsignals , 2 } ,
   { "R_rusagePtr_set_ru_nvcsw" , (DL_FUNC) & R_rusagePtr_set_ru_nvcsw , 2 } ,
   { "R_rusagePtr_set_ru_nivcsw" , (DL_FUNC) & R_rusagePtr_set_ru_nivcsw , 2 } ,
   { "R_free_rusage_finalizer" , (DL_FUNC) & R_free_rusage_finalizer , 1 } ,
   { "R_free_rusage" , (DL_FUNC) & R_free_rusage , 1 } ,
   { "R_new_rusage" , (DL_FUNC) & R_new_rusage , 0 } , 
    {NULL, NULL, 0} 
};
 
#ifdef __cplusplus
extern "C"
#endif
void
#ifdef HAVE_VISIBILITY_ATTRIBUTE
__attribute__ ((visibility ("default")))
#endif
R_init_Rgetrusage(DllInfo *dll)
{
	R_registerRoutines(dll,  NULL, CallEntries, NULL, NULL );
	R_useDynamicSymbols(dll, FALSE );
}
