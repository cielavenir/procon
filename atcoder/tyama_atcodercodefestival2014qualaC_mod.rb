#!/usr/bin/ruby
f=->(n){n/400-n/100+n/4}
a,b=gets.split.map(&:to_i)
p f.(b)-f.(a-1)