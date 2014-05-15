#!/usr/bin/ruby
a=gets.split.map(&:to_i).sort
m=[a[0]+a[1]-a[2],a[0]+a[2]-a[3],a[1]+a[2]-a[3]].max
puts m>0?"TRIANGLE":m<0?"IMPOSSIBLE":"SEGMENT"