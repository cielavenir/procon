#!/usr/bin/ruby
n,*x=`dd`.split.map &:to_i;s=x.sum
p *x.map{|e|(100*n-s+e*n)/2/n}
