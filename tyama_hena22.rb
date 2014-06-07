#!/usr/bin/env ruby
#http://qiita.com/torazuka/items/
#http://nabetani.sakura.ne.jp/hena/ord22irrpas/
STDOUT.sync=true
while gets
	a,b=$_.chomp.split(':')
	_x,_y=a.split('x').map(&:to_i)
	cells=[]
	if b
		cells=b.split(',').map{|e|
			l,t,w,h=e.split('').map(&:to_i)
			{x1:l.to_i+1,x2:l.to_i+1+w.to_i,y1:t.to_i+1,y2:t.to_i+1+h.to_i}
		}
	end

	m=(_y+1).times.map{[nil]*(_x+1)}
	(_y+1).times{|y|m[y][0]=0}
	(_x+1).times{|x|m[0][x]=0}
	m[0][1]=1

	while !m[_y][_x]
	1.step(_y){|y|
		1.step(_x){|x|
			if (cell=cells.find{|e|e[:x1]<=x&&x<e[:x2] && e[:y1]<=y&&y<e[:y2]})
				if cell[:x1]==x && cell[:y1]==y
					cells_for_val=[]
					val=0
					unless (cell[:y1]...cell[:y2]).each{|dy|
						dcell=cells.find{|e|e[:x1]<=x-1&&x-1<e[:x2] && e[:y1]<=dy&&dy<e[:y2]}
						if !dcell||!cells_for_val.include?(dcell)
							cells_for_val.push(dcell)
							break if !m[dy][x-1]
							val+=m[dy][x-1]
						end
					}
						next
					end
					unless (cell[:x1]...cell[:x2]).each{|dx|
						dcell=cells.find{|e|e[:x1]<=dx&&dx<e[:x2] && e[:y1]<=y-1&&y-1<e[:y2]}
						if !dcell||!cells_for_val.include?(dcell)
							cells_for_val.push(dcell)
							break if !m[y-1][dx]
							val+=m[y-1][dx]
						end
					}
						next
					end
					(cell[:y1]...cell[:y2]).each{|dy|
						(cell[:x1]...cell[:x2]).each{|dx|
							m[dy][dx]=val%100
						}
					}
				end
			else
				next if !m[y-1][x] || !m[y][x-1]
				val=m[y-1][x]+m[y][x-1]
				m[y][x]=val%100
			end
		}
	}
	#m.each{|e|p e}
	end
	printf("%02d\n",m[_y][_x])
end