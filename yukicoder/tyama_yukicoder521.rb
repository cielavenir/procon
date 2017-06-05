#!/usr/bin/ruby
n,k=gets.split.map &:to_i
p k<1||n<k ? 0 : n%2==0||k!=(n+1)/2 ? n-2 : n-1
