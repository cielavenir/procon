#!/usr/bin/ruby
n=(gets.to_i-1)%40
n=n<20 ? n : 39-n
p n+1