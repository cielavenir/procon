#!/usr/bin/ruby
d=[[-1,-1],[-1,0],[-1,1],[0,-1],[0,1],[1,-1],[1,0],[1,1]]
while gets
g,z=$_.chomp.split(';')
h,w=g.split(',').map(&:to_i)
a=z.split('')
a=a.each_slice(w).to_a
h.times{|i|
	print w.times.map{|j|
		if a[i][j]=='*'
			'*'
		else
			d.select{|e|0<=i+e[0]&&i+e[0]<h && 0<=j+e[1]&&j+e[1]<w && a[i+e[0]][j+e[1]]=='*'}.count
		end
	}.join
}
puts
end