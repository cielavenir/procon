#!/usr/bin/ruby
n=gets.to_i;r=1+(n-2)*~-n*-~n/12.0;2.upto(n){|i|r+=2.0/i};p r