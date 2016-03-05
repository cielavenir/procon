#!/usr/bin/ruby
#http://qiita.com/Nabetani/items/8d7691e9bb7655c3b990
#http://nabetani.sakura.ne.jp/hena/orde02pire/
#Online: 16:35-16:53

STDOUT.sync=true
T=[*'0'..'9',*'A'..'Z',*'a'..'z']
H=62
W=62
while gets
	a=$_.chomp.split(':')
	n=a[0].to_i
	m=(H+1).times.map{[0]*(W+1)}
	a[1].split(',').each{|e|
		x,y=e.chars.map{|c|T.index(c)}
		m[y+1][x+1]=1
	}
	(H+1).times.map{|y|W.times.map{|x|m[y][x+1]+=m[y][x]}}
	H.times.map{|y|(W+1).times.map{|x|m[y+1][x]+=m[y][x]}}
	r=[]
	H.times{|y0|(y0+1).upto(H){|y1|W.times{|x0|(x0+1).upto(W){|x1|
		if m[y0][x0]-m[y1][x0]-m[y0][x1]+m[y1][x1]==n
			r<<(x1-x0)*(y1-y0)
		end
	}}}}
	z=r.minmax
	if !z[0]
		puts '-'
	else
		puts z*','
	end
end