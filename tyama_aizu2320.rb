#!/usr/bin/ruby
while (h,w,l=gets.split.map(&:to_i))!=[0,0,0]
d=[[0,-1],[1,0],[0,1],[-1,0]]
d0="NESW".split('')
f=(h+2).times.map{[1]*(w+2)}
g=(h+2).times.map{(w+2).times.map{[nil]*4}}
z=x=y=0
h.times{|i|
	s=gets.chomp
	w.times{|j|
		if (k=d0.index(s[j..j]))
			x=j+1;y=i+1;z=k
		end
		if s[j..j]!='#'
			f[i+1][j+1]=nil
		end
	}
}
c=0
while l>0
	break if g[y][x][z]&&(l%=c-g[y][x][z])==0
	g[y][x][z]=c
	z=(z+1)%4 while f[y+d[z][1]][x+d[z][0]]
	x+=d[z][0];y+=d[z][1]
	l-=1
	c+=1
end
puts "#{y} #{x} #{d0[z]}"
end