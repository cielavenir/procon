#!/usr/bin/ruby
s=0;gets;m=$<.map{|e|e.split.map &:to_i}.select{|a,b|s+=a;a>b}.map{|a,b|b}.min
p m ? s-m : 0
