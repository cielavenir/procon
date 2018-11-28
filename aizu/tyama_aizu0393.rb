#!/usr/bin/ruby
h,a,b=gets.split.map &:to_i;p (a..b).count{|i|h%i<1}
