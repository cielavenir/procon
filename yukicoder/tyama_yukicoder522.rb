#!/usr/bin/ruby
n=gets.to_i-3
0.upto(n){|a|a.upto(n-a){|b|c=n-a-b;b<=c&&(puts [a+1,b+1,c+1]*' ')}}
