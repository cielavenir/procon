#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i
l=a.reduce &:lcm
p a.map{|e|l/e}.sum%(10**9+7)
