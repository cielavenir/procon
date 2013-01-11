#!/usr/bin/env Rscript
x=scan("stdin")
i=1
repeat{
  j=x[i]
  if(j==0)break
  y=x[(i+1):(i+j)]
  cat((sum(y)-max(y)-min(y))%/%(length(y)-2))
  cat("\n")
  i=i+j+1
}