#!/usr/bin/ruby
x,y=gets.split.map &:to_i;p x/x.gcd(y)-1