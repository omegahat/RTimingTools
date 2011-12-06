\name{rusage}
\alias{rusage}
\title{Resource usage by an R command}
\description{
  This function is similar in spirit to
  \code{\link[base]{system.time}}
  except it provides information about
  more than just the time used.
  Rather, it includes all the information from the
  \code{rusage} structure in C.
  This includes information about the maximum resident size of the
  program, shared memory size, unshared data and stack size,
  number of page reclaims and faults, swaps, input and output
  operations, messages sent and received,
  and voluntary and involuntary context switches.
  This returns the difference of the 
  
}
\usage{
rusage(expr, gcFirst = TRUE)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{expr}{the R command to be evaluated}
  \item{gcFirst}{ a logical value indicating whether to perform garbage
    collection before evaluatingthe command.
  }
}
\details{
  This makes a call to \code{getrusage}
  before and after evaluating the expression and then takes the
  difference between the two.
}
\value{
  An object of class \code{rusage}
  which contains the 
}
\references{
 Man page for getrusage
}
\author{Duncan Temple Lang}
\seealso{\code{\link{getrusage}}}
\examples{

rusage(replicate(10, mean(rnorm(10000))))
}
\keyword{programming}
\concept{timing}
\concept{performance}
