#!/usr/bin/ruby
p 1901.step(2000).reduce(0){|s,y|s+=1.step(12).count{|m|Time.gm(y,m,1).wday==0}}