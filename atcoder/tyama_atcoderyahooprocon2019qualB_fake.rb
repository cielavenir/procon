#!/usr/bin/ruby
s=0;`dd`.split.map{|e|s+=e.to_i};puts s==15?'YES':'NO'
