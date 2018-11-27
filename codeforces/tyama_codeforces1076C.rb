#!/usr/bin/ruby
gets;$<.each{|e|
n=e.to_i
d=n*(n-4)
puts d<0 ? :N : ('Y %.9f %.9f'%[n-x=(n-d**0.5)/2,x])
}
