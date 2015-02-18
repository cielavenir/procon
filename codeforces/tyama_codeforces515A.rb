#!/usr/bin/env ruby
a,b,s=gets.split.map(&:to_i)
d=a.abs+b.abs
puts d<=s&&d%2==s%2 ? :Yes : :No