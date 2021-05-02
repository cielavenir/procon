#!/usr/bin/ruby
n,*a=*`dd`.split.map(&:to_i),1e9,0;1.upto(n){|i|a<<[1,2].map{|e|a[-e]+(a[i]-a[i-e]).abs}.min};p a[-2]