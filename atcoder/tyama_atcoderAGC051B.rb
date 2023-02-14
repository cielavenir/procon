#!/usr/bin/ruby
p(8000).times{|i|puts'%d %d'%[i/20*20,i%400]}
#p 8000;20.times{|i|20.times{|j|20.times{|k|puts'%d %d'%[400*i+20*j,20*j+k]}}}
