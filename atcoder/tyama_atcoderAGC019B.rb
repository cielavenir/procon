#!/usr/bin/ruby
s=gets
n=s.size-1;n=n*~-n/2+1
h=Hash.new -1
s.chars{|c|n-=h[c]+=1}
p n
