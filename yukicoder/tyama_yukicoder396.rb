#!/usr/bin/ruby
n,m=gets.split.map(&:to_i);a=gets.split.map{|e|d,r=(e.to_i-1).divmod m;[r,m-r-1][d%2]};puts a[0]==a[1] ? :YES : :NO