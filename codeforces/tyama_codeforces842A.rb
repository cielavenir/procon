#!/usr/bin/ruby
l,r,x,y,k=gets.split.map &:to_i
l=(l+k-1)/k
r=r/k
puts l<=r && x<=r && l<=y ? :YES : :NO
