#!/usr/bin/ruby
n=gets.to_i;p n%2<1?(r=0;n/=2;r+=n/=5while n>0;r):0
