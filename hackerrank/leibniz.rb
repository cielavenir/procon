#!/usr/bin/ruby
gets;$<.map{|e|s=0;e.to_i.times{|i|s+=(-1)**i/(2*i+1.0)};p s}