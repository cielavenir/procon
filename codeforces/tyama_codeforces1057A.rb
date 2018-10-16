#!/usr/bin/ruby
a=$<.read.split.map &:to_i
x=a.size-1
r=[x+1]
while x>0;x=a[x]-1;r.unshift x+1 end
puts r*' '
