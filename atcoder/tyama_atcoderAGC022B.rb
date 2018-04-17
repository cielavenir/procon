#!/usr/bin/ruby
T=2,10,3,9,4,8,6,12;n=gets.to_i;puts n<4?'2 5 63':n.times.map{|i|i/8*12+T[(i-n%2)%8]}*' '
