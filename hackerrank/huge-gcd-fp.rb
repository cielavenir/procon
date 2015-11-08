#!/usr/bin/ruby
require 'prime'
def range_factor(r)
	r.each_with_object(Hash.new(0)){|i,h|i.prime_division.each{|n,p|h[n]+=p}}
end
gets
a=range_factor(gets.split.map(&:to_i))
gets
b=range_factor(gets.split.map(&:to_i))
b.each{|k,v|a[k]=[a[k],v].min}
a.each{|k,v|a[k]=[a[k],b[k]].min}
p a.map{|k,v|k**v}.reduce(:*)%1000000007