#!/usr/bin/ruby
require 'prime'
a=Prime.each(100000).to_a
m=543
loop{
z=(a.size-m).times.map{|i|a[i,m].reduce(:+)}.select{|e|e.prime?}[0]
if z then p z;exit end
m-=1
}