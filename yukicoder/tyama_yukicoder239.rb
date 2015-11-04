#!/usr/bin/ruby
gets
a=i=0
p$<.map(&:split).transpose.one?{|e|i+=1;a=i if~e.count('nyanpass')==-e.size}?a:-1