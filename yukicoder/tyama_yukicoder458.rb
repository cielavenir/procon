#!/usr/bin/ruby
require'prime'
a=[0,*[-1]*(n=gets.to_i)]
Prime.each(999){|e|n.downto(e){|i|a[i-e]>=0&&a[i]=[a[i-e]+1,a[i]].max}}
p a[n]
