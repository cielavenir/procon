#!/usr/bin/ruby
while gets
a,b=$_.split.map(&:to_i)
p ((a-b+1)..a).reduce(1){|s,e|s=s*e%10**6}
end