setClass('__priority_which', contains = 'BitwiseValue')
`__priority_whichValues` = BitwiseValue(structure(as.integer(c(0,
1,
2)),
names = c("PRIO_PROCESS",
"PRIO_PGRP",
"PRIO_USER")), class ='__priority_which')


setAs('numeric', '__priority_which', function(from) asEnumValue(from, `__priority_whichValues`, '__priority_which'))
setAs('character', '__priority_which', function(from) asEnumValue(from, `__priority_whichValues`, '__priority_which'))


`PRIO_PROCESS` <- BitwiseValue(0, 'PRIO_PROCESS', class = '__priority_which')
`PRIO_PGRP` <- BitwiseValue(1, 'PRIO_PGRP', class = '__priority_which')
`PRIO_USER` <- BitwiseValue(2, 'PRIO_USER', class = '__priority_which')
setClass('__rusage_who', contains = 'EnumValue')
`__rusage_whoValues` = EnumDef('__rusage_who', structure(as.integer(c(0,
-1)),
names = c("RUSAGE_SELF",
"RUSAGE_CHILDREN")))


setAs('numeric', '__rusage_who', function(from) asEnumValue(from, `__rusage_whoValues`, '__rusage_who'))
setAs('character', '__rusage_who', function(from) asEnumValue(from, `__rusage_whoValues`, '__rusage_who'))


`RUSAGE_SELF` <- GenericEnumValue('RUSAGE_SELF', 0, '__rusage_who')
`RUSAGE_CHILDREN` <- GenericEnumValue('RUSAGE_CHILDREN', -1, '__rusage_who')
setClass('__rlimit_resource', contains = 'EnumValue')
`__rlimit_resourceValues` = EnumDef('__rlimit_resource', structure(as.integer(c(0,
1,
2,
3,
4,
5,
7,
7,
9,
6,
8,
10,
11,
12,
13,
14,
15,
15)),
names = c("RLIMIT_CPU",
"RLIMIT_FSIZE",
"RLIMIT_DATA",
"RLIMIT_STACK",
"RLIMIT_CORE",
"__RLIMIT_RSS",
"RLIMIT_NOFILE",
"__RLIMIT_OFILE",
"RLIMIT_AS",
"__RLIMIT_NPROC",
"__RLIMIT_MEMLOCK",
"__RLIMIT_LOCKS",
"__RLIMIT_SIGPENDING",
"__RLIMIT_MSGQUEUE",
"__RLIMIT_NICE",
"__RLIMIT_RTPRIO",
"__RLIMIT_NLIMITS",
"__RLIM_NLIMITS")))


setAs('numeric', '__rlimit_resource', function(from) asEnumValue(from, `__rlimit_resourceValues`, '__rlimit_resource'))
setAs('character', '__rlimit_resource', function(from) asEnumValue(from, `__rlimit_resourceValues`, '__rlimit_resource'))


`RLIMIT_CPU` <- GenericEnumValue('RLIMIT_CPU', 0, '__rlimit_resource')
`RLIMIT_FSIZE` <- GenericEnumValue('RLIMIT_FSIZE', 1, '__rlimit_resource')
`RLIMIT_DATA` <- GenericEnumValue('RLIMIT_DATA', 2, '__rlimit_resource')
`RLIMIT_STACK` <- GenericEnumValue('RLIMIT_STACK', 3, '__rlimit_resource')
`RLIMIT_CORE` <- GenericEnumValue('RLIMIT_CORE', 4, '__rlimit_resource')
`__RLIMIT_RSS` <- GenericEnumValue('__RLIMIT_RSS', 5, '__rlimit_resource')
`RLIMIT_NOFILE` <- GenericEnumValue('RLIMIT_NOFILE', 7, '__rlimit_resource')
`__RLIMIT_OFILE` <- GenericEnumValue('__RLIMIT_OFILE', 7, '__rlimit_resource')
`RLIMIT_AS` <- GenericEnumValue('RLIMIT_AS', 9, '__rlimit_resource')
`__RLIMIT_NPROC` <- GenericEnumValue('__RLIMIT_NPROC', 6, '__rlimit_resource')
`__RLIMIT_MEMLOCK` <- GenericEnumValue('__RLIMIT_MEMLOCK', 8, '__rlimit_resource')
`__RLIMIT_LOCKS` <- GenericEnumValue('__RLIMIT_LOCKS', 10, '__rlimit_resource')
`__RLIMIT_SIGPENDING` <- GenericEnumValue('__RLIMIT_SIGPENDING', 11, '__rlimit_resource')
`__RLIMIT_MSGQUEUE` <- GenericEnumValue('__RLIMIT_MSGQUEUE', 12, '__rlimit_resource')
`__RLIMIT_NICE` <- GenericEnumValue('__RLIMIT_NICE', 13, '__rlimit_resource')
`__RLIMIT_RTPRIO` <- GenericEnumValue('__RLIMIT_RTPRIO', 14, '__rlimit_resource')
`__RLIMIT_NLIMITS` <- GenericEnumValue('__RLIMIT_NLIMITS', 15, '__rlimit_resource')
`__RLIM_NLIMITS` <- GenericEnumValue('__RLIM_NLIMITS', 15, '__rlimit_resource')
setClass('__itimer_which', contains = 'BitwiseValue')
`__itimer_whichValues` = BitwiseValue(structure(as.integer(c(0,
1,
2)),
names = c("ITIMER_REAL",
"ITIMER_VIRTUAL",
"ITIMER_PROF")), class ='__itimer_which')


setAs('numeric', '__itimer_which', function(from) asEnumValue(from, `__itimer_whichValues`, '__itimer_which'))
setAs('character', '__itimer_which', function(from) asEnumValue(from, `__itimer_whichValues`, '__itimer_which'))


`ITIMER_REAL` <- BitwiseValue(0, 'ITIMER_REAL', class = '__itimer_which')
`ITIMER_VIRTUAL` <- BitwiseValue(1, 'ITIMER_VIRTUAL', class = '__itimer_which')
`ITIMER_PROF` <- BitwiseValue(2, 'ITIMER_PROF', class = '__itimer_which')
