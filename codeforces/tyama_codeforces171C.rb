#!/usr/bin/ruby
n,*a=gets.split.map &:to_i;r=0;n.times{|i|r+=-~i*a[i]};p r