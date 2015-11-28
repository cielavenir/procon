#!/usr/bin/ruby
s='';10.times{s+=10.times.max_by{|i|puts s+i.to_s;STDOUT.flush;gets.to_i}.to_s}