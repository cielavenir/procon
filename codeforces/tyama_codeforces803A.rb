#!/usr/bin/ruby
n,k=gets.split.map(&:to_i)
if n*n<k
	p -1
	exit
end
a=n.times.map{[0]*n}
(0...n).each{|i|
	if k>0
		a[i][i]=1
		k-=1
	end
	(i+1...n).each{|j|
		if k>1
			a[i][j]=a[j][i]=1
			k-=2
		end
	}
}
puts a.map{|e|e*' '}
