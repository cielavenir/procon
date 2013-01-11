# reference: http://cse.naro.affrc.go.jp/takezawa/r-tips/r.html
# to execute:
# 1. source("icpc2007dA.R") in R prompt.
# 2. R --slave --vanilla < icpc2007dA.R 2>/dev/null

x=scan("A") #file io only
i=1
repeat{
  j=x[i]
  if(j==0)break
  y=x[(i+1):(i+j)]
  cat(floor( (sum(y)-max(y)-min(y))/(length(y)-2) ))
  cat("\n")
  i=i+j+1
}