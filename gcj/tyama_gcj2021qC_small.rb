#!/usr/bin/ruby
def solveA(a)
	r=0
	(a.length-1).times{|i|
		x=(i...a.length).min_by{|j|a[j]}
		a=a[0...i]+a[i..x].reverse+a[x+1..-1]
		r+=x-i+1
	}
	r
end
t=gets.to_i
t.times{|i|
	print 'Case #%d: '%(i+1)
	n,c=gets.split.map(&:to_i)
	x=[*1..n].permutation.find{|a|solveA(a)==c}
	puts x ? x*' ' : :IMPOSSIBLE
}
