library(RAutoGenRunTime)
setClass('fd_set', representation( '__fds_bits' = 'numeric' ))
setClass('fd_setPtr', contains = 'RC++Reference', prototype = list(classes = 'fd_setPtr'))


setMethod('$',  'fd_setPtr' , function(x, name  ) { 
 	 .fieldNames = c( '__fds_bits' )
	 idx = pmatch(name, .fieldNames)
	 if(is.na(idx))
	     stop("no such field ", name, " in fd_set. Should be one of ", paste(.fieldNames, collapse = ", "))
	 switch(name, '__fds_bits' = `fd_setPtr_get___fds_bits` )(x  )
	 
 })
setMethod('$<-',  'fd_setPtr' , function(x, name , value ) { 
 	 .fieldNames = c( '__fds_bits' )
	 idx = pmatch(name, .fieldNames)
	 if(is.na(idx))
	     stop("no such field ", name, " in fd_set. Should be one of ", paste(.fieldNames, collapse = ", "))
	 switch(name, '__fds_bits' = `fd_setPtr_set___fds_bits` )(x , value )
	 
 })
setMethod('names', 'fd_setPtr', 
	function(x) 
	c( '__fds_bits' ))


`fd_setPtr_get___fds_bits`  <- function(x  )
{
	.Call('R_fd_setPtr_get___fds_bits', x)
}
`fd_setPtr_set___fds_bits`  <- function(x , value )
{
	value = as.numeric( value ) 

 	if(length( value ) != 32 ) {
 	    arrayLengthWarning( value ,  32 )
 	    length( value ) <-  32 
	}


	.Call('R_fd_setPtr_set___fds_bits', x, value)
}



setAs( "fd_set" ,  "fd_setPtr" , 
function(from)
.Call('R_coerce_fd_set_fd_setPtr', from )
)
setAs( "fd_setPtr" ,  "fd_set" , 
function(from)
.Call('R_coerce_fd_setPtr_fd_set', from)
) 
new_fd_set =
function(..., .finalizer = FALSE)
{
	ans = .Call('R_new_fd_set')
	if((is.logical(.finalizer) && .finalizer) || length(.finalizer) > 0)
		addFinalizer(ans, .finalizer)
	
	args = list(...)
	na = pmatch(names(args), names(getSlots('fd_set')))
	if(any(is.na(na)))
	      stop('no fields match ', paste(names(args)[is.na(na)], collapse = ', '))
	
	for(i in names(args))
	  "$<-"(ans, i, args[[i]])
	
	ans
} 
setClass('timeval', representation( 'tv_sec' = 'numeric',
 'tv_usec' = 'numeric' ), prototype = list( `tv_sec` = as( 0 , 'integer'), `tv_usec` = as( 0 , 'integer') ))
setClass('timevalPtr', contains = 'RC++Reference', prototype = list(classes = 'timevalPtr'))


setMethod('$',  'timevalPtr' , function(x, name  ) { 
 	 .fieldNames = c( 'tv_sec',
		'tv_usec' )
	 idx = pmatch(name, .fieldNames)
	 if(is.na(idx))
	     stop("no such field ", name, " in timeval. Should be one of ", paste(.fieldNames, collapse = ", "))
	 switch(name, 'tv_sec' = `timevalPtr_get_tv_sec`,
		'tv_usec' = `timevalPtr_get_tv_usec` )(x  )
	 
 })
setMethod('$<-',  'timevalPtr' , function(x, name , value ) { 
 	 .fieldNames = c( 'tv_sec',
		'tv_usec' )
	 idx = pmatch(name, .fieldNames)
	 if(is.na(idx))
	     stop("no such field ", name, " in timeval. Should be one of ", paste(.fieldNames, collapse = ", "))
	 switch(name, 'tv_sec' = `timevalPtr_set_tv_sec`,
		'tv_usec' = `timevalPtr_set_tv_usec` )(x , value )
	 
 })
setMethod('names', 'timevalPtr', 
	function(x) 
	c( 'tv_sec', 'tv_usec' ))


`timevalPtr_get_tv_sec`  <- function(x  )
{
	.Call('R_timevalPtr_get_tv_sec', x)
}
`timevalPtr_get_tv_usec`  <- function(x  )
{
	.Call('R_timevalPtr_get_tv_usec', x)
}
`timevalPtr_set_tv_sec`  <- function(x , value )
{
	value = as( value , 'integer')
	.Call('R_timevalPtr_set_tv_sec', x, value)
}
`timevalPtr_set_tv_usec`  <- function(x , value )
{
	value = as( value , 'integer')
	.Call('R_timevalPtr_set_tv_usec', x, value)
}



setAs( "timeval" ,  "timevalPtr" , 
function(from)
.Call('R_coerce_timeval_timevalPtr', from )
)
setAs( "timevalPtr" ,  "timeval" , 
function(from)
.Call('R_coerce_timevalPtr_timeval', from)
) 
new_timeval =
function(..., .finalizer = FALSE)
{
	ans = .Call('R_new_timeval')
	if((is.logical(.finalizer) && .finalizer) || length(.finalizer) > 0)
		addFinalizer(ans, .finalizer)
	
	args = list(...)
	na = pmatch(names(args), names(getSlots('timeval')))
	if(any(is.na(na)))
	      stop('no fields match ', paste(names(args)[is.na(na)], collapse = ', '))
	
	for(i in names(args))
	  "$<-"(ans, i, args[[i]])
	
	ans
} 
setClass('timespec', representation( 'tv_sec' = 'numeric',
 'tv_nsec' = 'numeric' ), prototype = list( `tv_sec` = as( 0 , 'integer'), `tv_nsec` = as( 0 , 'integer') ))
setClass('timespecPtr', contains = 'RC++Reference', prototype = list(classes = 'timespecPtr'))


setMethod('$',  'timespecPtr' , function(x, name  ) { 
 	 .fieldNames = c( 'tv_sec',
		'tv_nsec' )
	 idx = pmatch(name, .fieldNames)
	 if(is.na(idx))
	     stop("no such field ", name, " in timespec. Should be one of ", paste(.fieldNames, collapse = ", "))
	 switch(name, 'tv_sec' = `timespecPtr_get_tv_sec`,
		'tv_nsec' = `timespecPtr_get_tv_nsec` )(x  )
	 
 })
setMethod('$<-',  'timespecPtr' , function(x, name , value ) { 
 	 .fieldNames = c( 'tv_sec',
		'tv_nsec' )
	 idx = pmatch(name, .fieldNames)
	 if(is.na(idx))
	     stop("no such field ", name, " in timespec. Should be one of ", paste(.fieldNames, collapse = ", "))
	 switch(name, 'tv_sec' = `timespecPtr_set_tv_sec`,
		'tv_nsec' = `timespecPtr_set_tv_nsec` )(x , value )
	 
 })
setMethod('names', 'timespecPtr', 
	function(x) 
	c( 'tv_sec', 'tv_nsec' ))


`timespecPtr_get_tv_sec`  <- function(x  )
{
	.Call('R_timespecPtr_get_tv_sec', x)
}
`timespecPtr_get_tv_nsec`  <- function(x  )
{
	.Call('R_timespecPtr_get_tv_nsec', x)
}
`timespecPtr_set_tv_sec`  <- function(x , value )
{
	value = as( value , 'integer')
	.Call('R_timespecPtr_set_tv_sec', x, value)
}
`timespecPtr_set_tv_nsec`  <- function(x , value )
{
	value = as( value , 'integer')
	.Call('R_timespecPtr_set_tv_nsec', x, value)
}



setAs( "timespec" ,  "timespecPtr" , 
function(from)
.Call('R_coerce_timespec_timespecPtr', from )
)
setAs( "timespecPtr" ,  "timespec" , 
function(from)
.Call('R_coerce_timespecPtr_timespec', from)
) 
new_timespec =
function(..., .finalizer = FALSE)
{
	ans = .Call('R_new_timespec')
	if((is.logical(.finalizer) && .finalizer) || length(.finalizer) > 0)
		addFinalizer(ans, .finalizer)
	
	args = list(...)
	na = pmatch(names(args), names(getSlots('timespec')))
	if(any(is.na(na)))
	      stop('no fields match ', paste(names(args)[is.na(na)], collapse = ', '))
	
	for(i in names(args))
	  "$<-"(ans, i, args[[i]])
	
	ans
} 
setClass('__sigset_t', representation( '__val' = 'numeric' ))
setClass('__sigset_tPtr', contains = 'RC++Reference', prototype = list(classes = '__sigset_tPtr'))


setMethod('$',  '__sigset_tPtr' , function(x, name  ) { 
 	 .fieldNames = c( '__val' )
	 idx = pmatch(name, .fieldNames)
	 if(is.na(idx))
	     stop("no such field ", name, " in __sigset_t. Should be one of ", paste(.fieldNames, collapse = ", "))
	 switch(name, '__val' = `__sigset_tPtr_get___val` )(x  )
	 
 })
setMethod('$<-',  '__sigset_tPtr' , function(x, name , value ) { 
 	 .fieldNames = c( '__val' )
	 idx = pmatch(name, .fieldNames)
	 if(is.na(idx))
	     stop("no such field ", name, " in __sigset_t. Should be one of ", paste(.fieldNames, collapse = ", "))
	 switch(name, '__val' = `__sigset_tPtr_set___val` )(x , value )
	 
 })
setMethod('names', '__sigset_tPtr', 
	function(x) 
	c( '__val' ))


`__sigset_tPtr_get___val`  <- function(x  )
{
	.Call('R___sigset_tPtr_get___val', x)
}
`__sigset_tPtr_set___val`  <- function(x , value )
{
	value = as.numeric( value ) 

 	if(length( value ) != 32 ) {
 	    arrayLengthWarning( value ,  32 )
 	    length( value ) <-  32 
	}


	.Call('R___sigset_tPtr_set___val', x, value)
}



setAs( "__sigset_t" ,  "__sigset_tPtr" , 
function(from)
.Call('R_coerce___sigset_t___sigset_tPtr', from )
)
setAs( "__sigset_tPtr" ,  "__sigset_t" , 
function(from)
.Call('R_coerce___sigset_tPtr___sigset_t', from)
) 
new___sigset_t =
function(..., .finalizer = FALSE)
{
	ans = .Call('R_new___sigset_t')
	if((is.logical(.finalizer) && .finalizer) || length(.finalizer) > 0)
		addFinalizer(ans, .finalizer)
	
	args = list(...)
	na = pmatch(names(args), names(getSlots('__sigset_t')))
	if(any(is.na(na)))
	      stop('no fields match ', paste(names(args)[is.na(na)], collapse = ', '))
	
	for(i in names(args))
	  "$<-"(ans, i, args[[i]])
	
	ans
} 
setClass('timezone', representation( 'tz_minuteswest' = 'integer',
 'tz_dsttime' = 'integer' ), prototype = list( `tz_minuteswest` = as( 0 , 'integer'), `tz_dsttime` = as( 0 , 'integer') ))
setClass('timezonePtr', contains = 'RC++Reference', prototype = list(classes = 'timezonePtr'))


setMethod('$',  'timezonePtr' , function(x, name  ) { 
 	 .fieldNames = c( 'tz_minuteswest',
		'tz_dsttime' )
	 idx = pmatch(name, .fieldNames)
	 if(is.na(idx))
	     stop("no such field ", name, " in timezone. Should be one of ", paste(.fieldNames, collapse = ", "))
	 switch(name, 'tz_minuteswest' = `timezonePtr_get_tz_minuteswest`,
		'tz_dsttime' = `timezonePtr_get_tz_dsttime` )(x  )
	 
 })
setMethod('$<-',  'timezonePtr' , function(x, name , value ) { 
 	 .fieldNames = c( 'tz_minuteswest',
		'tz_dsttime' )
	 idx = pmatch(name, .fieldNames)
	 if(is.na(idx))
	     stop("no such field ", name, " in timezone. Should be one of ", paste(.fieldNames, collapse = ", "))
	 switch(name, 'tz_minuteswest' = `timezonePtr_set_tz_minuteswest`,
		'tz_dsttime' = `timezonePtr_set_tz_dsttime` )(x , value )
	 
 })
setMethod('names', 'timezonePtr', 
	function(x) 
	c( 'tz_minuteswest', 'tz_dsttime' ))


`timezonePtr_get_tz_minuteswest`  <- function(x  )
{
	.Call('R_timezonePtr_get_tz_minuteswest', x)
}
`timezonePtr_get_tz_dsttime`  <- function(x  )
{
	.Call('R_timezonePtr_get_tz_dsttime', x)
}
`timezonePtr_set_tz_minuteswest`  <- function(x , value )
{
	value = as( value , 'integer')
	.Call('R_timezonePtr_set_tz_minuteswest', x, value)
}
`timezonePtr_set_tz_dsttime`  <- function(x , value )
{
	value = as( value , 'integer')
	.Call('R_timezonePtr_set_tz_dsttime', x, value)
}



setAs( "timezone" ,  "timezonePtr" , 
function(from)
.Call('R_coerce_timezone_timezonePtr', from )
)
setAs( "timezonePtr" ,  "timezone" , 
function(from)
.Call('R_coerce_timezonePtr_timezone', from)
) 
new_timezone =
function(..., .finalizer = FALSE)
{
	ans = .Call('R_new_timezone')
	if((is.logical(.finalizer) && .finalizer) || length(.finalizer) > 0)
		addFinalizer(ans, .finalizer)
	
	args = list(...)
	na = pmatch(names(args), names(getSlots('timezone')))
	if(any(is.na(na)))
	      stop('no fields match ', paste(names(args)[is.na(na)], collapse = ', '))
	
	for(i in names(args))
	  "$<-"(ans, i, args[[i]])
	
	ans
} 
setClass('timeval', representation( 'tv_sec' = 'numeric',
 'tv_usec' = 'numeric' ), prototype = list( `tv_sec` = as( 0 , 'integer'), `tv_usec` = as( 0 , 'integer') ))
setClass('timevalPtr', contains = 'RC++Reference', prototype = list(classes = 'timevalPtr'))


setClass('itimerval', representation( 'it_interval' = 'timeval',
 'it_value' = 'timeval' ))
setClass('itimervalPtr', contains = 'RC++Reference', prototype = list(classes = 'itimervalPtr'))


setMethod('$',  'itimervalPtr' , function(x, name  ) { 
 	 .fieldNames = c( 'it_interval',
		'it_value' )
	 idx = pmatch(name, .fieldNames)
	 if(is.na(idx))
	     stop("no such field ", name, " in itimerval. Should be one of ", paste(.fieldNames, collapse = ", "))
	 switch(name, 'it_interval' = `itimervalPtr_get_it_interval`,
		'it_value' = `itimervalPtr_get_it_value` )(x  )
	 
 })
setMethod('$<-',  'itimervalPtr' , function(x, name , value ) { 
 	 .fieldNames = c( 'it_interval',
		'it_value' )
	 idx = pmatch(name, .fieldNames)
	 if(is.na(idx))
	     stop("no such field ", name, " in itimerval. Should be one of ", paste(.fieldNames, collapse = ", "))
	 switch(name, 'it_interval' = `itimervalPtr_set_it_interval`,
		'it_value' = `itimervalPtr_set_it_value` )(x , value )
	 
 })
setMethod('names', 'itimervalPtr', 
	function(x) 
	c( 'it_interval', 'it_value' ))


`itimervalPtr_get_it_interval`  <- function(x  )
{
	.Call('R_itimervalPtr_get_it_interval', x)
}
`itimervalPtr_get_it_value`  <- function(x  )
{
	.Call('R_itimervalPtr_get_it_value', x)
}
`itimervalPtr_set_it_interval`  <- function(x , value )
{
	value = asReference( value ,  "timeval" )
	.Call('R_itimervalPtr_set_it_interval', x, value)
}
`itimervalPtr_set_it_value`  <- function(x , value )
{
	value = asReference( value ,  "timeval" )
	.Call('R_itimervalPtr_set_it_value', x, value)
}



setAs( "itimerval" ,  "itimervalPtr" , 
function(from)
.Call('R_coerce_itimerval_itimervalPtr', from )
)
setAs( "itimervalPtr" ,  "itimerval" , 
function(from)
.Call('R_coerce_itimervalPtr_itimerval', from)
) 
new_itimerval =
function(..., .finalizer = FALSE)
{
	ans = .Call('R_new_itimerval')
	if((is.logical(.finalizer) && .finalizer) || length(.finalizer) > 0)
		addFinalizer(ans, .finalizer)
	
	args = list(...)
	na = pmatch(names(args), names(getSlots('itimerval')))
	if(any(is.na(na)))
	      stop('no fields match ', paste(names(args)[is.na(na)], collapse = ', '))
	
	for(i in names(args))
	  "$<-"(ans, i, args[[i]])
	
	ans
} 
setClass('rlimit', representation( 'rlim_cur' = 'numeric',
 'rlim_max' = 'numeric' ), prototype = list( `rlim_cur` = as( 0 , 'integer'), `rlim_max` = as( 0 , 'integer') ))
setClass('rlimitPtr', contains = 'RC++Reference', prototype = list(classes = 'rlimitPtr'))


setMethod('$',  'rlimitPtr' , function(x, name  ) { 
 	 .fieldNames = c( 'rlim_cur',
		'rlim_max' )
	 idx = pmatch(name, .fieldNames)
	 if(is.na(idx))
	     stop("no such field ", name, " in rlimit. Should be one of ", paste(.fieldNames, collapse = ", "))
	 switch(name, 'rlim_cur' = `rlimitPtr_get_rlim_cur`,
		'rlim_max' = `rlimitPtr_get_rlim_max` )(x  )
	 
 })
setMethod('$<-',  'rlimitPtr' , function(x, name , value ) { 
 	 .fieldNames = c( 'rlim_cur',
		'rlim_max' )
	 idx = pmatch(name, .fieldNames)
	 if(is.na(idx))
	     stop("no such field ", name, " in rlimit. Should be one of ", paste(.fieldNames, collapse = ", "))
	 switch(name, 'rlim_cur' = `rlimitPtr_set_rlim_cur`,
		'rlim_max' = `rlimitPtr_set_rlim_max` )(x , value )
	 
 })
setMethod('names', 'rlimitPtr', 
	function(x) 
	c( 'rlim_cur', 'rlim_max' ))


`rlimitPtr_get_rlim_cur`  <- function(x  )
{
	.Call('R_rlimitPtr_get_rlim_cur', x)
}
`rlimitPtr_get_rlim_max`  <- function(x  )
{
	.Call('R_rlimitPtr_get_rlim_max', x)
}
`rlimitPtr_set_rlim_cur`  <- function(x , value )
{
	value = as( value , 'integer')
	.Call('R_rlimitPtr_set_rlim_cur', x, value)
}
`rlimitPtr_set_rlim_max`  <- function(x , value )
{
	value = as( value , 'integer')
	.Call('R_rlimitPtr_set_rlim_max', x, value)
}



setAs( "rlimit" ,  "rlimitPtr" , 
function(from)
.Call('R_coerce_rlimit_rlimitPtr', from )
)
setAs( "rlimitPtr" ,  "rlimit" , 
function(from)
.Call('R_coerce_rlimitPtr_rlimit', from)
) 
new_rlimit =
function(..., .finalizer = FALSE)
{
	ans = .Call('R_new_rlimit')
	if((is.logical(.finalizer) && .finalizer) || length(.finalizer) > 0)
		addFinalizer(ans, .finalizer)
	
	args = list(...)
	na = pmatch(names(args), names(getSlots('rlimit')))
	if(any(is.na(na)))
	      stop('no fields match ', paste(names(args)[is.na(na)], collapse = ', '))
	
	for(i in names(args))
	  "$<-"(ans, i, args[[i]])
	
	ans
} 
setClass('timeval', representation( 'tv_sec' = 'numeric',
 'tv_usec' = 'numeric' ), prototype = list( `tv_sec` = as( 0 , 'integer'), `tv_usec` = as( 0 , 'integer') ))
setClass('timevalPtr', contains = 'RC++Reference', prototype = list(classes = 'timevalPtr'))


setClass('rusage', representation( 'ru_utime' = 'timeval',
 'ru_stime' = 'timeval',
 'ru_maxrss' = 'numeric',
 'ru_ixrss' = 'numeric',
 'ru_idrss' = 'numeric',
 'ru_isrss' = 'numeric',
 'ru_minflt' = 'numeric',
 'ru_majflt' = 'numeric',
 'ru_nswap' = 'numeric',
 'ru_inblock' = 'numeric',
 'ru_oublock' = 'numeric',
 'ru_msgsnd' = 'numeric',
 'ru_msgrcv' = 'numeric',
 'ru_nsignals' = 'numeric',
 'ru_nvcsw' = 'numeric',
 'ru_nivcsw' = 'numeric' ), prototype = list( `ru_maxrss` = as( 0 , 'integer'), `ru_ixrss` = as( 0 , 'integer'), `ru_idrss` = as( 0 , 'integer'), `ru_isrss` = as( 0 , 'integer'), `ru_minflt` = as( 0 , 'integer'), `ru_majflt` = as( 0 , 'integer'), `ru_nswap` = as( 0 , 'integer'), `ru_inblock` = as( 0 , 'integer'), `ru_oublock` = as( 0 , 'integer'), `ru_msgsnd` = as( 0 , 'integer'), `ru_msgrcv` = as( 0 , 'integer'), `ru_nsignals` = as( 0 , 'integer'), `ru_nvcsw` = as( 0 , 'integer'), `ru_nivcsw` = as( 0 , 'integer') ))
setClass('rusagePtr', contains = 'RC++Reference', prototype = list(classes = 'rusagePtr'))


setMethod('$',  'rusagePtr' , function(x, name  ) { 
 	 .fieldNames = c( 'ru_utime',
		'ru_stime',
		'ru_maxrss',
		'ru_ixrss',
		'ru_idrss',
		'ru_isrss',
		'ru_minflt',
		'ru_majflt',
		'ru_nswap',
		'ru_inblock',
		'ru_oublock',
		'ru_msgsnd',
		'ru_msgrcv',
		'ru_nsignals',
		'ru_nvcsw',
		'ru_nivcsw' )
	 idx = pmatch(name, .fieldNames)
	 if(is.na(idx))
	     stop("no such field ", name, " in rusage. Should be one of ", paste(.fieldNames, collapse = ", "))
	 switch(name, 'ru_utime' = `rusagePtr_get_ru_utime`,
		'ru_stime' = `rusagePtr_get_ru_stime`,
		'ru_maxrss' = `rusagePtr_get_ru_maxrss`,
		'ru_ixrss' = `rusagePtr_get_ru_ixrss`,
		'ru_idrss' = `rusagePtr_get_ru_idrss`,
		'ru_isrss' = `rusagePtr_get_ru_isrss`,
		'ru_minflt' = `rusagePtr_get_ru_minflt`,
		'ru_majflt' = `rusagePtr_get_ru_majflt`,
		'ru_nswap' = `rusagePtr_get_ru_nswap`,
		'ru_inblock' = `rusagePtr_get_ru_inblock`,
		'ru_oublock' = `rusagePtr_get_ru_oublock`,
		'ru_msgsnd' = `rusagePtr_get_ru_msgsnd`,
		'ru_msgrcv' = `rusagePtr_get_ru_msgrcv`,
		'ru_nsignals' = `rusagePtr_get_ru_nsignals`,
		'ru_nvcsw' = `rusagePtr_get_ru_nvcsw`,
		'ru_nivcsw' = `rusagePtr_get_ru_nivcsw` )(x  )
	 
 })
setMethod('$<-',  'rusagePtr' , function(x, name , value ) { 
 	 .fieldNames = c( 'ru_utime',
		'ru_stime',
		'ru_maxrss',
		'ru_ixrss',
		'ru_idrss',
		'ru_isrss',
		'ru_minflt',
		'ru_majflt',
		'ru_nswap',
		'ru_inblock',
		'ru_oublock',
		'ru_msgsnd',
		'ru_msgrcv',
		'ru_nsignals',
		'ru_nvcsw',
		'ru_nivcsw' )
	 idx = pmatch(name, .fieldNames)
	 if(is.na(idx))
	     stop("no such field ", name, " in rusage. Should be one of ", paste(.fieldNames, collapse = ", "))
	 switch(name, 'ru_utime' = `rusagePtr_set_ru_utime`,
		'ru_stime' = `rusagePtr_set_ru_stime`,
		'ru_maxrss' = `rusagePtr_set_ru_maxrss`,
		'ru_ixrss' = `rusagePtr_set_ru_ixrss`,
		'ru_idrss' = `rusagePtr_set_ru_idrss`,
		'ru_isrss' = `rusagePtr_set_ru_isrss`,
		'ru_minflt' = `rusagePtr_set_ru_minflt`,
		'ru_majflt' = `rusagePtr_set_ru_majflt`,
		'ru_nswap' = `rusagePtr_set_ru_nswap`,
		'ru_inblock' = `rusagePtr_set_ru_inblock`,
		'ru_oublock' = `rusagePtr_set_ru_oublock`,
		'ru_msgsnd' = `rusagePtr_set_ru_msgsnd`,
		'ru_msgrcv' = `rusagePtr_set_ru_msgrcv`,
		'ru_nsignals' = `rusagePtr_set_ru_nsignals`,
		'ru_nvcsw' = `rusagePtr_set_ru_nvcsw`,
		'ru_nivcsw' = `rusagePtr_set_ru_nivcsw` )(x , value )
	 
 })
setMethod('names', 'rusagePtr', 
	function(x) 
	c( 'ru_utime', 'ru_stime', 'ru_maxrss', 'ru_ixrss', 'ru_idrss', 'ru_isrss', 'ru_minflt', 'ru_majflt', 'ru_nswap', 'ru_inblock', 'ru_oublock', 'ru_msgsnd', 'ru_msgrcv', 'ru_nsignals', 'ru_nvcsw', 'ru_nivcsw' ))


`rusagePtr_get_ru_utime`  <- function(x  )
{
	.Call('R_rusagePtr_get_ru_utime', x)
}
`rusagePtr_get_ru_stime`  <- function(x  )
{
	.Call('R_rusagePtr_get_ru_stime', x)
}
`rusagePtr_get_ru_maxrss`  <- function(x  )
{
	.Call('R_rusagePtr_get_ru_maxrss', x)
}
`rusagePtr_get_ru_ixrss`  <- function(x  )
{
	.Call('R_rusagePtr_get_ru_ixrss', x)
}
`rusagePtr_get_ru_idrss`  <- function(x  )
{
	.Call('R_rusagePtr_get_ru_idrss', x)
}
`rusagePtr_get_ru_isrss`  <- function(x  )
{
	.Call('R_rusagePtr_get_ru_isrss', x)
}
`rusagePtr_get_ru_minflt`  <- function(x  )
{
	.Call('R_rusagePtr_get_ru_minflt', x)
}
`rusagePtr_get_ru_majflt`  <- function(x  )
{
	.Call('R_rusagePtr_get_ru_majflt', x)
}
`rusagePtr_get_ru_nswap`  <- function(x  )
{
	.Call('R_rusagePtr_get_ru_nswap', x)
}
`rusagePtr_get_ru_inblock`  <- function(x  )
{
	.Call('R_rusagePtr_get_ru_inblock', x)
}
`rusagePtr_get_ru_oublock`  <- function(x  )
{
	.Call('R_rusagePtr_get_ru_oublock', x)
}
`rusagePtr_get_ru_msgsnd`  <- function(x  )
{
	.Call('R_rusagePtr_get_ru_msgsnd', x)
}
`rusagePtr_get_ru_msgrcv`  <- function(x  )
{
	.Call('R_rusagePtr_get_ru_msgrcv', x)
}
`rusagePtr_get_ru_nsignals`  <- function(x  )
{
	.Call('R_rusagePtr_get_ru_nsignals', x)
}
`rusagePtr_get_ru_nvcsw`  <- function(x  )
{
	.Call('R_rusagePtr_get_ru_nvcsw', x)
}
`rusagePtr_get_ru_nivcsw`  <- function(x  )
{
	.Call('R_rusagePtr_get_ru_nivcsw', x)
}
`rusagePtr_set_ru_utime`  <- function(x , value )
{
	value = asReference( value ,  "timeval" )
	.Call('R_rusagePtr_set_ru_utime', x, value)
}
`rusagePtr_set_ru_stime`  <- function(x , value )
{
	value = asReference( value ,  "timeval" )
	.Call('R_rusagePtr_set_ru_stime', x, value)
}
`rusagePtr_set_ru_maxrss`  <- function(x , value )
{
	value = as( value , 'integer')
	.Call('R_rusagePtr_set_ru_maxrss', x, value)
}
`rusagePtr_set_ru_ixrss`  <- function(x , value )
{
	value = as( value , 'integer')
	.Call('R_rusagePtr_set_ru_ixrss', x, value)
}
`rusagePtr_set_ru_idrss`  <- function(x , value )
{
	value = as( value , 'integer')
	.Call('R_rusagePtr_set_ru_idrss', x, value)
}
`rusagePtr_set_ru_isrss`  <- function(x , value )
{
	value = as( value , 'integer')
	.Call('R_rusagePtr_set_ru_isrss', x, value)
}
`rusagePtr_set_ru_minflt`  <- function(x , value )
{
	value = as( value , 'integer')
	.Call('R_rusagePtr_set_ru_minflt', x, value)
}
`rusagePtr_set_ru_majflt`  <- function(x , value )
{
	value = as( value , 'integer')
	.Call('R_rusagePtr_set_ru_majflt', x, value)
}
`rusagePtr_set_ru_nswap`  <- function(x , value )
{
	value = as( value , 'integer')
	.Call('R_rusagePtr_set_ru_nswap', x, value)
}
`rusagePtr_set_ru_inblock`  <- function(x , value )
{
	value = as( value , 'integer')
	.Call('R_rusagePtr_set_ru_inblock', x, value)
}
`rusagePtr_set_ru_oublock`  <- function(x , value )
{
	value = as( value , 'integer')
	.Call('R_rusagePtr_set_ru_oublock', x, value)
}
`rusagePtr_set_ru_msgsnd`  <- function(x , value )
{
	value = as( value , 'integer')
	.Call('R_rusagePtr_set_ru_msgsnd', x, value)
}
`rusagePtr_set_ru_msgrcv`  <- function(x , value )
{
	value = as( value , 'integer')
	.Call('R_rusagePtr_set_ru_msgrcv', x, value)
}
`rusagePtr_set_ru_nsignals`  <- function(x , value )
{
	value = as( value , 'integer')
	.Call('R_rusagePtr_set_ru_nsignals', x, value)
}
`rusagePtr_set_ru_nvcsw`  <- function(x , value )
{
	value = as( value , 'integer')
	.Call('R_rusagePtr_set_ru_nvcsw', x, value)
}
`rusagePtr_set_ru_nivcsw`  <- function(x , value )
{
	value = as( value , 'integer')
	.Call('R_rusagePtr_set_ru_nivcsw', x, value)
}



setAs( "rusage" ,  "rusagePtr" , 
function(from)
.Call('R_coerce_rusage_rusagePtr', from )
)
setAs( "rusagePtr" ,  "rusage" , 
function(from)
.Call('R_coerce_rusagePtr_rusage', from)
) 
new_rusage =
function(..., .finalizer = FALSE)
{
	ans = .Call('R_new_rusage')
	if((is.logical(.finalizer) && .finalizer) || length(.finalizer) > 0)
		addFinalizer(ans, .finalizer)
	
	args = list(...)
	na = pmatch(names(args), names(getSlots('rusage')))
	if(any(is.na(na)))
	      stop('no fields match ', paste(names(args)[is.na(na)], collapse = ', '))
	
	for(i in names(args))
	  "$<-"(ans, i, args[[i]])
	
	ans
} 
`ITIMER_REAL` <- GenericEnumValue( "ITIMER_REAL" ,  0 )
`ITIMER_VIRTUAL` <- GenericEnumValue( "ITIMER_VIRTUAL" ,  1 )
`ITIMER_PROF` <- GenericEnumValue( "ITIMER_PROF" ,  2 )
`RLIMIT_CPU` <- GenericEnumValue( "RLIMIT_CPU" ,  0 )
`RLIMIT_FSIZE` <- GenericEnumValue( "RLIMIT_FSIZE" ,  1 )
`RLIMIT_DATA` <- GenericEnumValue( "RLIMIT_DATA" ,  2 )
`RLIMIT_STACK` <- GenericEnumValue( "RLIMIT_STACK" ,  3 )
`RLIMIT_CORE` <- GenericEnumValue( "RLIMIT_CORE" ,  4 )
`__RLIMIT_RSS` <- GenericEnumValue( "__RLIMIT_RSS" ,  5 )
`RLIMIT_NOFILE` <- GenericEnumValue( "RLIMIT_NOFILE" ,  7 )
`__RLIMIT_OFILE` <- GenericEnumValue( "__RLIMIT_OFILE" ,  7 )
`RLIMIT_AS` <- GenericEnumValue( "RLIMIT_AS" ,  9 )
`__RLIMIT_NPROC` <- GenericEnumValue( "__RLIMIT_NPROC" ,  6 )
`__RLIMIT_MEMLOCK` <- GenericEnumValue( "__RLIMIT_MEMLOCK" ,  8 )
`__RLIMIT_LOCKS` <- GenericEnumValue( "__RLIMIT_LOCKS" ,  10 )
`__RLIMIT_SIGPENDING` <- GenericEnumValue( "__RLIMIT_SIGPENDING" ,  11 )
`__RLIMIT_MSGQUEUE` <- GenericEnumValue( "__RLIMIT_MSGQUEUE" ,  12 )
`__RLIMIT_NICE` <- GenericEnumValue( "__RLIMIT_NICE" ,  13 )
`__RLIMIT_RTPRIO` <- GenericEnumValue( "__RLIMIT_RTPRIO" ,  14 )
`__RLIMIT_NLIMITS` <- GenericEnumValue( "__RLIMIT_NLIMITS" ,  15 )
`__RLIM_NLIMITS` <- GenericEnumValue( "__RLIM_NLIMITS" ,  15 )
`RUSAGE_SELF` <- GenericEnumValue( "RUSAGE_SELF" ,  0 )
`RUSAGE_CHILDREN` <- GenericEnumValue( "RUSAGE_CHILDREN" ,  -1 )
`PRIO_PROCESS` <- GenericEnumValue( "PRIO_PROCESS" ,  0 )
`PRIO_PGRP` <- GenericEnumValue( "PRIO_PGRP" ,  1 )
`PRIO_USER` <- GenericEnumValue( "PRIO_USER" ,  2 )
select <-
function( r2590, r2599 = new_fd_set(), r2610 = new_fd_set(), r2623 = new_fd_set(), r2641 = new_timeval(), .copy = c( 'r2599' = FALSE, 'r2610' = FALSE, 'r2623' = FALSE, 'r2641' = FALSE ) )  
{
     r2590 = as( r2590 , 'integer')
     r2599 = asReference( r2599 ,  "fd_setPtr" )
     r2610 = asReference( r2610 ,  "fd_setPtr" )
     r2623 = asReference( r2623 ,  "fd_setPtr" )
     r2641 = asReference( r2641 ,  "timevalPtr" )
    .copy = validateCopy(.copy, c('r2599', 'r2610', 'r2623', 'r2641'))

    .Call('R_select', r2590, r2599, r2610, r2623, r2641, .copy, as.integer(sum(!is.na(.copy)) + 1 ))
}
pselect <-
function( r2600, r2611 = new_fd_set(), r2624 = new_fd_set(), r2642 = new_fd_set(), r2661 = new_timespec(), r2683 = new___sigset_t(), .copy = c( 'r2611' = FALSE, 'r2624' = FALSE, 'r2642' = FALSE, 'r2661' = FALSE, 'r2683' = FALSE ) )  
{
     r2600 = as( r2600 , 'integer')
     r2611 = asReference( r2611 ,  "fd_setPtr" )
     r2624 = asReference( r2624 ,  "fd_setPtr" )
     r2642 = asReference( r2642 ,  "fd_setPtr" )
     r2661 = asReference( r2661 ,  "timespecPtr" )
     r2683 = asReference( r2683 ,  "__sigset_tPtr" )
    .copy = validateCopy(.copy, c('r2611', 'r2624', 'r2642', 'r2661', 'r2683'))

    .Call('R_pselect', r2600, r2611, r2624, r2642, r2661, r2683, .copy, as.integer(sum(!is.na(.copy)) + 1 ))
}
gettimeofday <-
function( r2612 = new_timeval(), r2626 = new_timezone(), .copy = c( 'r2612' = FALSE, 'r2626' = FALSE ) )  
{
     r2612 = asReference( r2612 ,  "timevalPtr" )
     r2626 = asReference( r2626 ,  "timezonePtr" )
    .copy = validateCopy(.copy, c('r2612', 'r2626'))

    .Call('R_gettimeofday', r2612, r2626, .copy, as.integer(sum(!is.na(.copy)) + 1 ))
}
settimeofday <-
function( r2627 = new_timeval(), r2647 = new_timezone(), .copy = c( 'r2627' = FALSE, 'r2647' = FALSE ) )  
{
     r2627 = asReference( r2627 ,  "timevalPtr" )
     r2647 = asReference( r2647 ,  "timezonePtr" )
    .copy = validateCopy(.copy, c('r2627', 'r2647'))

    .Call('R_settimeofday', r2627, r2647, .copy, as.integer(sum(!is.na(.copy)) + 1 ))
}
adjtime <-
function( r2648 = new_timeval(), r2668 = new_timeval(), .copy = c( 'r2648' = FALSE, 'r2668' = FALSE ) )  
{
     r2648 = asReference( r2648 ,  "timevalPtr" )
     r2668 = asReference( r2668 ,  "timevalPtr" )
    .copy = validateCopy(.copy, c('r2648', 'r2668'))

    .Call('R_adjtime', r2648, r2668, .copy, as.integer(sum(!is.na(.copy)) + 1 ))
}
getitimer <-
function( r2669, r2691 = new_itimerval(), .copy = c( 'r2691' = FALSE ) )  
{
     r2669 = as( r2669 , 'integer')
     r2691 = asReference( r2691 ,  "itimervalPtr" )
    .copy = validateCopy(.copy, c('r2691'))

    .Call('R_getitimer', r2669, r2691, .copy, as.integer(sum(!is.na(.copy)) + 1 ))
}
setitimer <-
function( r2692, r2713 = new_itimerval(), r2738 = new_itimerval(), .copy = c( 'r2713' = FALSE, 'r2738' = FALSE ) )  
{
     r2692 = as( r2692 , 'integer')
     r2713 = asReference( r2713 ,  "itimervalPtr" )
     r2738 = asReference( r2738 ,  "itimervalPtr" )
    .copy = validateCopy(.copy, c('r2713', 'r2738'))

    .Call('R_setitimer', r2692, r2713, r2738, .copy, as.integer(sum(!is.na(.copy)) + 1 ))
}
utimes <-
function( r2714, r2739 = new_timeval(), .copy = c( 'r2739' = FALSE ) )  
{
     r2714 = if(is(r2714, 'charRef'))
   	    r2714
   	 else
   	    as.character( r2714 )
     r2739 = asReference( r2739 ,  "timevalPtr" )
    .copy = validateCopy(.copy, c('r2739'))

    .Call('R_utimes', r2714, r2739, .copy, as.integer(sum(!is.na(.copy)) + 1 ))
}
lutimes <-
function( r2714, r2739 = new_timeval(), .copy = c( 'r2739' = FALSE ) )  
{
     r2714 = if(is(r2714, 'charRef'))
   	    r2714
   	 else
   	    as.character( r2714 )
     r2739 = asReference( r2739 ,  "timevalPtr" )
    .copy = validateCopy(.copy, c('r2739'))

    .Call('R_lutimes', r2714, r2739, .copy, as.integer(sum(!is.na(.copy)) + 1 ))
}
futimes <-
function( r2763, r2789 = new_timeval(), .copy = c( 'r2789' = FALSE ) )  
{
     r2763 = as( r2763 , 'integer')
     r2789 = asReference( r2789 ,  "timevalPtr" )
    .copy = validateCopy(.copy, c('r2789'))

    .Call('R_futimes', r2763, r2789, .copy, as.integer(sum(!is.na(.copy)) + 1 ))
}
getrlimit <-
function( r2790, r2812 = new_rlimit(), .copy = c( 'r2812' = FALSE ) )  
{
     r2790 = as( r2790 , 'integer')
     r2812 = asReference( r2812 ,  "rlimitPtr" )
    .copy = validateCopy(.copy, c('r2812'))

    .Call('R_getrlimit', r2790, r2812, .copy, as.integer(sum(!is.na(.copy)) + 1 ))
}
setrlimit <-
function( r2813, r2833 = new_rlimit(), .copy = c( 'r2833' = FALSE ) )  
{
     r2813 = as( r2813 , 'integer')
     r2833 = asReference( r2833 ,  "rlimitPtr" )
    .copy = validateCopy(.copy, c('r2833'))

    .Call('R_setrlimit', r2813, r2833, .copy, as.integer(sum(!is.na(.copy)) + 1 ))
}
getrusage <-
function( r2834, r2854 = new_rusage(), .copy = c( 'r2854' = FALSE ) )  
{
     r2834 = as( r2834 , 'integer')
     r2854 = asReference( r2854 ,  "rusagePtr" )
    .copy = validateCopy(.copy, c('r2854'))

    .Call('R_getrusage', r2834, r2854, .copy, as.integer(sum(!is.na(.copy)) + 1 ))
}
getpriority <-
function( r2855, r2874 )  
{
     r2855 = as( r2855 , 'integer')
     r2874 = as( r2874 , 'integer')

    .Call('R_getpriority', r2855, r2874)
}
setpriority <-
function( r2875, r2891, r2907 )  
{
     r2875 = as( r2875 , 'integer')
     r2891 = as( r2891 , 'integer')
     r2907 = as( r2907 , 'integer')

    .Call('R_setpriority', r2875, r2891, r2907)
}
