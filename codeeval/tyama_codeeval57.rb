#!/usr/bin/ruby
while gets
h,w,a=$_.chomp.split(';')
h=h.to_i
w=w.to_i
a=a.split
f=(h+2).times.map{[nil]*(w+2)}
d=[[1,0],[0,1],[-1,0],[0,-1]]
1.step(h){|i|
	1.step(w){|j|
		f[i][j]=1
	}
}
x=y=1
f[y][x]=nil
print a[(y-1)*w+x-1]
loop{
	break if 4.times.none?{|i|
		if f[y+d[i][1]][x+d[i][0]]
			d.rotate!(i)
			x+=d[0][0];y+=d[0][1]
			f[y][x]=nil
			print ' '+a[(y-1)*w+x-1]
			true
		end
	}
}
puts
end