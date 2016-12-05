#!/usr/bin/ruby
n,k=gets.split.map(&:to_i)
s=gets
a,b=['G','T'].map{|e|s.index(e)}.sort
puts (b-a)%k==0 && a.step(b,k).all?{|i|s[i]!='#'} ? :YES : :NO
