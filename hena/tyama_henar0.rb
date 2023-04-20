#!/usr/bin/ruby
#coding:utf-8

# https://nabetani.github.io/q/pages/r0/
# https://qiita.com/Nabetani/items/03f983f0835b928a9524

def genCoors
	return to_enum(:genCoors) if !block_given?
	i=0
	while true
		(0..i).each{|j|
			yield [j, i-j]
		}
		i+=1
	end
end

# 正方形なので、重なる場合は端点を共有する
def overlap?(points1, points2, rev=false)
	# points1の頂点がpoints2の内部に存在するか判定する
	ym = points2[0][0]
	xm = points2[0][1]
	yM = points2[2][0]
	xM = points2[2][1]
	if points1.any?{|y,x|
		ym<=y && y<=yM && xm<=x && x<=xM
	}
		return true
	end
	if rev
		return false
	else
		return overlap?(points2, points1, true)
	end
end

def output(squares, maxI)
	# 最大の正方形(squares[maxI])を1単位ずつ太らせて重なりを判定する
	# ただし端点で接する場合を除外するため、squares[maxI]以外のsquareを2個rotateし一致を判定する
	squares = squares.to_a  # copy
	(my,mx), m = squares.delete_at(maxI)
	my -= 1
	mx -= 1
	m += 2
	pointsm = [[my,mx], [my+m-1,mx], [my+m-1, mx+m-1], [my,mx+m-1]]
	ret = []
	squares.each{|(sy,sx), s|
		points2 = [[sy,sx], [sy+s-1,sx], [sy+s-1, sx+s-1], [sy,sx+s-1]]
		points2.rotate!(2)
		if 4.times.none?{|i|pointsm[i]==points2[i]} and overlap?(points2, pointsm, true)
			ret << s
		end
	}
	return ret.sort
end

def solve(a)
	squares = []  # [[y座標, x座標], 辺長]
	a.each{|e|
		genCoors.each{|y,x|
			points = [[y,x], [y+e-1,x], [y+e-1, x+e-1], [y,x+e-1]]
			if squares.all?{|(sy,sx), s|
				points2 = [[sy,sx], [sy+s-1,sx], [sy+s-1, sx+s-1], [sy,sx+s-1]]
				!overlap?(points, points2)
			}
				squares << [[y,x], e]
				break
			end
		}
	}
	#p squares
	return output(squares, [*0...a.size].max_by{|i|a[i]})
end

while s=gets
	puts solve(s.chomp.split(',').map &:to_i)*','
	STDOUT.flush
end
