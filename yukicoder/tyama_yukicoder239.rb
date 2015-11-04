#!/usr/bin/ruby
gets
a=i=0
p$<.map(&:split).transpose.one?{|e|i+=1;~e.count('nyanpass')==-e.size&&a=i}?a:-1