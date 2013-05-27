#!/usr/bin/ruby
a,b=gets.split.map &:to_i;puts"%d %d %f"%[a/b,a%b,a/b.to_f]