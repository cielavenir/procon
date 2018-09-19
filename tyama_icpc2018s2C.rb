#!/usr/bin/ruby
n=gets.to_i;r=n%2;(2..(n**0.5).to_i).map{|i|n%i<1&&(r+=-~i/2;n/i>i&&r+=-~(n/i)/2)};p r
