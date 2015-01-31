#!/usr/bin/ruby
a,b=$<.map{|e|e.split('.').map(&:to_i)}
puts (a<=>b)<0?:NO:'YES'