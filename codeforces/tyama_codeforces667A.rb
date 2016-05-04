#!/usr/bin/ruby
d,h,v,e=gets.split.map(&:to_f)
v/=Math::PI*d*d/4
puts v<e ? "NO" : "YES\n"+(h/(v-e)).to_s