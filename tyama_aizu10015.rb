#!/usr/bin/ruby
h={}
gets.to_i.times{h[gets.split]=1}
'SHCD'.chars{|e|1.step(13){|i|puts e+' '+i.to_s if !h[[e,i.to_s]]}}