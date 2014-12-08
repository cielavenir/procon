#!/usr/bin/ruby
C=gets.to_f
a,b=gets.split.map(&:to_f)
S=((b-a)/2)**2*Math::PI
p C*2*Math::PI*S * ((b+a)/2)