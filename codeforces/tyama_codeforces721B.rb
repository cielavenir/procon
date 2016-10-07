#!/usr/bin/ruby
n,k=gets.split.map &:to_i
a=$<.map{|e|e.chomp.size}
x=a.pop
a.sort!
l,r=[:>=,:>].map{|o|
	(0...n).bsearch{|i|a[i].send(o,x)}||n
}
r-=1
puts [l+l/k*5+1,r+r/k*5+1]*' '
