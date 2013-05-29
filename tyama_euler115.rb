#!/usr/bin/ruby
require 'enumerable/lazy' if RUBY_VERSION<'2.0'
N=50
a=[1]*N+[2]
p N+1+(N+1..1/0.0).lazy.map{|i|(a<<1+a[0..(i-N-1)].reduce(:+)+a[i-1]).last}.take_while{|e|e<10**6}.count