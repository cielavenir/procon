#!/usr/bin/ruby
n,*a=$<.map &:to_i;m=(a+a).chunk{|e|e}.map{|k,v|v.size}.max;p m==n*2?-1:-~m/2