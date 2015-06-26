#!/usr/bin/ruby
gets
i=0
a=$<.map{|e|a,b=e.split.map &:to_i
[a-3e4*b,i+=1]}.max
puts a[0]<5e5?:NO:[:YES]+[a[1]]*6