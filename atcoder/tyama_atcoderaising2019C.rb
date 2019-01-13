#!/usr/bin/ruby
D=[[-1,0],[0,-1],[1,0],[0,1]]
def fill(_x,_y,_c)
	r=[0,0]
	q=[[_x,_y,_c]]
	while !q.empty?
		x,y,c=q.shift
		r[c]+=1
		D.each{|dx,dy|
			nx=x+dx
			ny=y+dy
			if 0<=nx&&nx<$n&&0<=ny&&ny<$m&&$T[ny][nx]&&$T[ny][nx]==c^1
				$T[ny][nx]=nil
				q.push([nx,ny,c^1])
			end
		}
	end
	r[0]*r[1]
end
$m,$n=gets.split.map(&:to_i)
$T=$m.times.map{gets.chomp.chars.map{|c|c=='#' ? 1 : 0}}
r=0
$m.times{|i|
	$n.times{|j|
		if $T[i][j]
			c=$T[i][j]
			$T[i][j]=nil
			r+=fill(j,i,c)
		end
	}
}
p r
