#!/usr/bin/ruby
n=k=gets.to_i;n-=k while n>k=n&-n;p n
