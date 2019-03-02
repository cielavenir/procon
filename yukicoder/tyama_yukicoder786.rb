#!/usr/bin/ruby
a=[1,1]
(2..gets.to_i).each{a<<a[-2]+a[-1]}
p a[-1]
