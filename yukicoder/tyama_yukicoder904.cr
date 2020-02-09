#!/usr/bin/env crystal
n=gets.not_nil!.to_i-1
m=c=d=0
n.times{x,y=gets.not_nil!.split.map &.to_i;m=[m,x+y].max;c+=x;d+=y}
p d-[0,d-c,m-c].max+1
