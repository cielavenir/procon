#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
z=[n-m,0].max*2
p [n,m].min+((-1+Math.sqrt(1+4*z))/2).ceil
__END__
x2+x-z>=0
x=(-1+Math.sqrt(1+4*z))/2
