slotArith =
           function(e1, e2) {
              ids = names(getSlots(class(e1)))
              ans = new(class(e1))
              for(i in ids) 
                slot(ans, i) = callGeneric(slot(e1, i), slot(e2, i))
              ans
           }  

setMethod("Arith", c("rusage", "rusage"), slotArith)
setMethod("Arith", c("timeval", "timeval"), slotArith)



rusage =
function(expr, gcFirst = TRUE)
{
    loc.frame <- parent.frame()
    if (gcFirst) 
        gc(FALSE)
    expr <- substitute(expr)

    start = getrusage(RUSAGE_SELF, .copy = c(TRUE))[[2]]

    eval(expr, envir = loc.frame)    

    end = getrusage(RUSAGE_SELF, .copy = c(TRUE))[[2]]

    end - start
}

