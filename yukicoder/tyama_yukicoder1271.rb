#!/usr/bin/ruby
k=gets.to_i;p k<1 ? Math::PI**2/6 : (1..k).reduce{|s,i|s+1.0/i}/k
