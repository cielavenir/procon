#!/usr/bin/ruby
def insertionSort(a,g)
	for i in g..a.size-1
		v = a[i]
		j = i - g
		while j >= 0 && a[j] > v
			a[j+g] = a[j]
			j = j - g
			$cnt+=1
			a[j+g] = v
		end
	end
end

def shellSort(a)
	$cnt = 0
	g = []
	h = 1
	while h <= a.size
		g << h
		h = 3*h+1
	end
	g.reverse!
	m = g.size
	p m
	puts g*' '
	for i in 0..m-1
		insertionSort(a,g[i])
	end
end

a=gets.to_i.times.map{gets.to_i}
shellSort(a)
p $cnt
puts a