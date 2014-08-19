#!/usr/bin/ruby
require'rational';gets;a=gets.split.map(&:to_i);p a.size*a.reduce(&:gcd)