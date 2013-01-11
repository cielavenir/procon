#!/usr/bin/ruby
a=[1,1]
2.step(100){|i|a<<a[i-1]+a[i-2]}
while gets
p a[$_.to_i]
end