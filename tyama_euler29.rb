#!/usr/bin/ruby
n=gets.to_i
h={}
2.step(n){|a|2.step(n){|b|h[a**b]=1}}
p h.size
__END__
100