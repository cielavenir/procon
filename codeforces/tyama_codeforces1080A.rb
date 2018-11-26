#!/usr/bin/ruby
a,b=gets.split.map &:to_i;r=0;[2,5,8].map{|i|r+=(i*a+b-1)/b};p r
