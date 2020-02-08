#!/usr/bin/env crystal
c=gets.not_nil!.to_f
a=gets.not_nil!.split.map(&.to_f)
s=((a[1]-a[0])/2)**2*Math::PI
puts "%.9f" % [c*2*Math::PI*s * ((a[1]+a[0])/2)]
