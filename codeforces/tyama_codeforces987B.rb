#!/usr/bin/ruby
a,b=gets.split.map &:to_f
puts'=><'[b*Math.log(a)<=>a*Math.log(b)]
