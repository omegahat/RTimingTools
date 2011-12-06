setMethod("Arith", c("timeval", "timeval"),
           function(e1, e2) {
             new("timeval", tv_sec = callGeneric(e1@tv_sec, e2@tv_sec),
                            tv_usec = callGeneric(e1@tv_usec, e2@tv_usec))
             })



setMethod("Arith", c("rusage", "rusage"),
           function(e1, e2) {

             ans = new("rusage")
             for(id in names(getSlots("rusage")))
                slot(ans, id) <- callGeneric(slot(e1, id), slot(e2, id))

             ans
           })



           

