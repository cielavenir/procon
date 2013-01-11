#!/usr/bin/ruby
require'rational';while gets
a,b=$_.split.map &:to_i;p a.gcd(b)end