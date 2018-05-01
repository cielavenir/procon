#!/usr/bin/ruby
k,n,s,q=gets.split.map &:to_i
p~-((n+~-s)/s*k+q)/q
