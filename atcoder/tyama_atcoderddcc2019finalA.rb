#!/usr/bin/ruby
s=`dd`;a=s.scan(/\>+/).map(&:size).sort;a[0]||=0;a[-1]+=1
p a.map{|e|r=0;2.upto(e+1){|i|r+=1.0/i};r}.reduce(:+)+s.count('-')-1
