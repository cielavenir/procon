#!/usr/bin/ruby
n,h,*a=`dd`.split.map &:to_i
a.each{|e|h/=h.gcd(e)}
puts h<2 ? :YES : :NO
