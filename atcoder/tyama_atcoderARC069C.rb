#!/usr/bin/ruby
n,m=gets.split.map &:to_i;p m<n*2?m/2:(m-n*2)/4+n
