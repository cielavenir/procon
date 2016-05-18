#!/usr/bin/ruby
s='';10.times{|j|s+=10.times.max_by{|i|puts '0'*j+i.to_s+'0'*(10-j-1);STDOUT.flush;'10 unlocked'==(t=gets.chop)&&exit;t.to_i}.to_s};puts s