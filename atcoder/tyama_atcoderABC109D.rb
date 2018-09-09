#!/usr/bin/ruby
H,W=gets.split.map &:to_i
M=H.times.map{gets.split.map &:to_i}
Z=H.times.flat_map{|h|[*0...W].send([:to_a,:reverse][h%2]).map{|e|[h,e]}}
R=[]
Z.each_cons(2){|(y1,x1),(y2,x2)|
	if M[y1][x1]%2>0
		M[y2][x2]+=1
		R<<[y1+1,x1+1,y2+1,x2+1]*' '
	end
}
p R.size
puts R
