#!/usr/bin/ruby
n=gets.to_i
s=i=0
s+=i+=1while s<n
(1..i).map{|e|e!=s-n&&p(e)}
