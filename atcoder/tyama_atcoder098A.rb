#!/usr/bin/ruby
a,b=gets.split.map &:to_i;p %w(+ - *).map{|o|a.send o,b}.max
