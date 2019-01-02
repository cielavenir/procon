#!/usr/bin/ruby
h=Hash.new 0
(a=gets.chomp).chars{|c|h[c]+=1}
(b=gets.chomp).chars{|c|h[c]-=1}
k=h.values.map(&:abs).reduce :+
p (a.size+b.size-k)/2+k+(b.index(a[0])&&a.index(b[0])?0:1)
