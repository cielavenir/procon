#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i
x=-a.sum%n
d,r=(100+n).divmod n
p d-(x>r ? 1 : 0)
