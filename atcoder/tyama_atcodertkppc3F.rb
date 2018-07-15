#!/usr/bin/ruby
r=t=0;gets.to_i.times.map{gets.split.map &:to_i}.sort_by{|a,b|a*1.0/b}.map{|a,b|r+=t*b;t+=a};p r
