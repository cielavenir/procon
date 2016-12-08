#!/usr/bin/ruby
x=gets.to_f
r=Math::PI**2/6
1.upto(999999){|k|r+=(x+k)**-2-k**-2}
p r
