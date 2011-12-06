# Alternatives:
#    C code http://gwenole.beauchesne.info/projects/cpuinfo/
cpuInfo.Linux =
function()
{
 txt = system("cat /proc/cpuinfo", intern = TRUE)
 m = read.dcf(textConnection(txt))
 colnames(m) = gsub("\\s*$", "", colnames(m))

 structure(
 list(mhz = m[,"cpu MHz"],
      cache = m[, 'cache size'],
      cores = m[, 'cpu cores'],
      model = m[, 'model name'],
      vendor = m[, 'vendor_id']),
           class = c("LinuxCPUInfo", "CPUInfo"))
      
     
}
