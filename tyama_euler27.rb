#!/usr/bin/ruby
require 'prime'
def len(a,b) n=0;while(n*n+a*n+b).prime? do n+=1 end;n end
p -999.step(999).map{|a|-999.step(999).map{|b|[len(a,b),a*b]}.max}.max[1]