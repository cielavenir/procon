#!/usr/bin/ruby
while gets
h,w,a=$_.chomp.split(';')
h=h.to_i
w=w.to_i
a=a.chomp.split
m=(h+2).times.map{[0]*(w+2)}
f=(h+2).times.map{[1]*(w+2)}
d=[[1,0],[0,1],[-1,0],[0,-1]]
1.step(h){|i|
	1.step(w){|j|
		f[i][j]=nil
		m[i][j]=a.shift
	}
}
x=y=1
f[y][x]=1
print m[y][x]
while true
	break if 4.times.none?{|i|
		if !f[y+d[i][1]][x+d[i][0]]
			d.rotate!(i)
			x+=d[0][0];y+=d[0][1]
			f[y][x]=1
			print ' '+m[y][x]
			true
		end
	}
end
puts
end