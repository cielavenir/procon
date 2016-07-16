#!/usr/bin/ruby
t,s,x=gets.split.map(&:to_i)
puts ((t<=x&&x%s==t%s) || (t+1<x&&x%s==(t+1)%s)) ? :YES : :NO