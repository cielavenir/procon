#!/usr/bin/ruby
require'rational'
gets;p gets.split.map(&:to_i).reduce{|s,e|s/s.gcd(e)*e}