#!/usr/bin/ruby
n,*l,k=`dd`.split.map &:to_i
p (0..1e9).bsearch{|h|l.map{|e|(e/h).to_i}.reduce(:+)<k}
