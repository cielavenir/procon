#!/usr/bin/ruby
require 'enumerable/lazy' if RUBY_VERSION<'2.0'
a,b=2,1;p (0..1/0.0).lazy.map{a,b=a*2+b*3,a+b*2;s=2*(a%3==1?a+1:a-1)}.take_while{|s|s<=10**9}.reduce(:+)