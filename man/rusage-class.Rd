\name{rusage-class}
\docType{class}
\alias{rusage-class}
\alias{Arith,rusage,rusage-method}
\alias{coerce,rusage,rusagePtr-method}
\alias{coerce,rusagePtr,rusage-method}

\title{Class "rusage" ~~~ }
\description{	 ~~ A concise (1-5 lines) description of what the class is.  ~~}
\section{Objects from the Class}{
Objects can be created by calls of the form \code{new("rusage", ...)}.
	 ~~ describe objects here ~~ 
}
\section{Slots}{
	 \describe{
    \item{\code{ru_utime}:}{Object of class \code{"timeval"} ~~ }
    \item{\code{ru_stime}:}{Object of class \code{"timeval"} ~~ }
    \item{\code{ru_maxrss}:}{Object of class \code{"numeric"} ~~ }
    \item{\code{ru_ixrss}:}{Object of class \code{"numeric"} ~~ }
    \item{\code{ru_idrss}:}{Object of class \code{"numeric"} ~~ }
    \item{\code{ru_isrss}:}{Object of class \code{"numeric"} ~~ }
    \item{\code{ru_minflt}:}{Object of class \code{"numeric"} ~~ }
    \item{\code{ru_majflt}:}{Object of class \code{"numeric"} ~~ }
    \item{\code{ru_nswap}:}{Object of class \code{"numeric"} ~~ }
    \item{\code{ru_inblock}:}{Object of class \code{"numeric"} ~~ }
    \item{\code{ru_oublock}:}{Object of class \code{"numeric"} ~~ }
    \item{\code{ru_msgsnd}:}{Object of class \code{"numeric"} ~~ }
    \item{\code{ru_msgrcv}:}{Object of class \code{"numeric"} ~~ }
    \item{\code{ru_nsignals}:}{Object of class \code{"numeric"} ~~ }
    \item{\code{ru_nvcsw}:}{Object of class \code{"numeric"} ~~ }
    \item{\code{ru_nivcsw}:}{Object of class \code{"numeric"} ~~ }
  }
}
\section{Methods}{
  \describe{
    \item{Arith}{\code{signature(e1 = "rusage", e2 = "rusage")}: ... }
    \item{coerce}{\code{signature(from = "rusage", to = "rusagePtr")}: ... }
    \item{coerce}{\code{signature(from = "rusagePtr", to = "rusage")}: ... }
	 }
}
\references{ ~put references to the literature/web site here ~ }
\author{ ~~who you are~~ }
\note{ ~~further notes~~ }

 ~Make other sections like Warning with \section{Warning }{....} ~

\seealso{
	~~objects to See Also as \code{\link{~~fun~~}}, ~~~
	or \code{\linkS4class{CLASSNAME}} for links to other classes
}
\examples{
showClass("rusage")
}
\keyword{classes}
