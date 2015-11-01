#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
a=gets.split.map(&:to_i).sort
i=0
divs=[]
while i*i<=n
	i+=1
	next if n%i!=0
	divs<< i
	divs<< n/i if i*i<n
end
divs.sort!
median=(a[a.size/2]+a[~-a.size/2])/2.0
idx2=(0...divs.size).bsearch{|i|divs[i]>=median}||divs.size
x=idx2<divs.size ? a.map{|e|(e-divs[idx2]).abs}.reduce(:+) : Float::INFINITY
idx1=idx2-1
y=idx1>=0 ? a.map{|e|(e-divs[idx1]).abs}.reduce(:+) : Float::INFINITY
p [x,y].min