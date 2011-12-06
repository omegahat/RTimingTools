\name{getrusage}
\alias{getrusage}
\title{Call to C routine getrusage}
\description{
  This is an interface to the C routine \code{getrusage()}.
  It fills in the fields in a C-level \code{struct rusage}.
  The C-level structure can be be supplied by the caller
  or, alternatively, the default value of the \code{x__usage}
  parameter provides a new instance of that object.
  The C object can be used as is and the fields accessed from R,
  or alternatively it can be copied to a \code{\link{rusage-class}}
  object in R.
}
\usage{
getrusage(x__who, x__usage = new_rusage(), .copy = c(x__usage = FALSE))
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{x__who}{either \code{RUSAGE_SELF} or \code{RUSAGE_CHILDREN}
    indicating whether to get information about this process
    or the sub-processes spawned, typically by a call to
    \code{\link[base]{system}}.
    One can only specify one of these, but one can call the function
    two times with different values for this argument to
    get the measurements for both this and child processes.
  }
  \item{x__usage}{an object of class \code{rusagePtr}
    One can pass in a previously allocated value,
    either explicitly via \code{new_rusage()},
    or implicitly by reusing an object returned
    from a previous call to this function, \code{getrusage}.
  }
  \item{.copy}{a logical value indicating whether the
    \code{rusage} structure passed in \code{x__usage}
    should be copied from the C structure to an R object
    of class \code{rusage} or left as a reference to the
    C structure.
  }
}
\details{
  This is programmatically generated code using the
  \code{RGCCTranslationUnit}
}
\value{
  A list of length 2.
  The first element is an integer giving the return value of the
  C routine \code{getrusage}.  The second element
  depends on the value of the \code{.code} argument.
  If this is \code{.code = FALSE}, the second element
  is an R object of class \code{rusagePtr}
  which is a reference to the C-level structure passed
  as the value for \code{x__usage}.
  If \code{.copy} is TRUE, the second element is
  an object of class \code{\link{rusage-class}}
  which is an R-level copy of the C-level structure.
}
\references{Man page for \code{getrusage}.}
\author{ Duncan Temple Lang}
\seealso{
\code{\link{rusage}}
}
\examples{

 start = getrusage(RUSAGE_SELF)
 invisible(replicate(100, mean(rnorm(1000))))
 end = getrusage(RUSAGE_SELF)

 end$ru_time - start$ru_utime
 end$ru_stime - start$ru_stime

  # Get the result as a regular R-level object,
  # not a reference to a C-level structure.
 ru = getrusage(RUSAGE_SELF, .copy = TRUE)[[2]]

 ru@majflt
}
\keyword{programming}
\concept{resource usage}
