#!/usr/bin/ruby
r=1;gets.chomp[1..-1].bytes{|b|r+=b==48?9:b-48};p r