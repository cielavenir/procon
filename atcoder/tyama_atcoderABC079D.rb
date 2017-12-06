#!/usr/bin/ruby
gets
a=10.times.map{gets.split.map &:to_i}
10.times{|k|10.times{|i|10.times{|j|
	a[i][j]=[a[i][j],a[i][k]+a[k][j]].min
}}}
r=0
$<.each{|e|
	e.split.map(&:to_i).each{|i|r+=a[i][1] if i!=-1}
}
p r
