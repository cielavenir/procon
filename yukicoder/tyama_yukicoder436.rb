#!/usr/bin/ruby
x,y=gets.scan /((.)\2*)/;p [x[0].size-1,y[0].size].min
