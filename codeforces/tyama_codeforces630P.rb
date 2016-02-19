#!/usr/bin/ruby
n,r=gets.split.map &:to_i;p n*r**2*Math.sin(Math::PI/n)*Math.cos(Math::PI*(n/2)/n)/Math.cos(Math::PI*(n/2-1)/n)