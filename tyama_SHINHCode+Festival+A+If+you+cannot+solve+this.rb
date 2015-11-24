#!/usr/bin/ruby
puts $<.map{|e|n,*a=e.split.map &:to_i;n*2*a[0]>a.reduce(:+)?:Pass: :Fail}