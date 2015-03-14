#!/usr/bin/ruby
gets;p$<.map{|s|s.to_i 1+s.chars.map{|e|e.to_i 36}.max}.min