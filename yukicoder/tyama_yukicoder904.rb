#!/usr/bin/ruby
gets
m=c=d=0
$<.map{|e|x,y=e.split.map &:to_i;m=[m,x+y].max;c+=x;d+=y}
p d-[0,d-c,m-c].max+1
