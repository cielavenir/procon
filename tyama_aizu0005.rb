#!/usr/bin/ruby
require'rational';while gets
a,b=$_.split.map &:to_i;puts"#{g=a.gcd(b)} #{a/g*b}"end