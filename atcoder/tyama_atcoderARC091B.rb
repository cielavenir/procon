#!/usr/bin/ruby
a,b=gets.split.map &:to_i;p (a..b).count{|i|i.to_s==i.to_s.reverse}
