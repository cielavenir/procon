#!/usr/bin/ruby
D=[[-1,0],[1,0],[0,-1],[0,1]]
$h={[0,0]=>1}
#def s(n) n.abs.to_s.chars.map(&:to_i).reduce(:+) end
def s(n)
	r=0
	x=n.abs
	while x>0
		r+=x%10
		x/=10
	end
	r
end
queue=[[0,0]]
until queue.empty?
	x,y=queue.shift
	D.each{|e|
		if !$h[[x+e[0],y+e[1]]] && s(x+e[0])+s(y+e[1])<20
			$h[[x+e[0],y+e[1]]]=1
			queue<<[x+e[0],y+e[1]]
		end
	}
end
p $h.size