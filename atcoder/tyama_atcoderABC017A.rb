#!/usr/bin/ruby
#p$<.map{|e|n,m=e.split.map &:to_i;n*m/10}.reduce(:+)
s=0;$<.map{|e|n,m=e.split.map &:to_i;s+=n*m/10};p s