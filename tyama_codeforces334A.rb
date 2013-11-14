#!/usr/bin/ruby
n=gets.to_i
a=[*1..n*n].each_slice(n).to_a.transpose
puts (a[0...n/2]+a[n/2..-1].map(&:reverse)).transpose.map{|e|e*' '}