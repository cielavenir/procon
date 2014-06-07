#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/34bf2a05099a47e193b6
#http://nabetani.sakura.ne.jp/hena/ord22irrpas/
STDOUT.sync=true
while gets
	a,b=$_.chomp.split(':')
	_x,_y=a.split('x').map(&:to_i)
	cells=[]
	if b
		cells=b.split(',').map{|e|
			l,t,w,h=e.split('').map(&:to_i)
			#番兵を設けるため1を足す。高さ/幅から端点の座標に変更。
			{:x1=>l.to_i+1,:x2=>l.to_i+1+w.to_i,:y1=>t.to_i+1,:y2=>t.to_i+1+h.to_i}
		}
	end

	m=(_y+1).times.map{[nil]*(_x+1)}
	(_y+1).times{|y|m[y][0]=0}
	(_x+1).times{|x|m[0][x]=0}
	m[0][1]=1 #m[1][0]=1でも可。適当。

	while !m[_y][_x] # 右下が埋まるまで
		1.step(_y){|y|
			1.step(_x){|x|
				next if m[y][x] # 既に埋まっていたらスキップ
				#1x1のセルでなければ
				if cell=cells.find{|e|e[:x1]<=x&&x<e[:x2] && e[:y1]<=y&&y<e[:y2]}
					#セルの右上を見ている時に限り左・上隣を見る
					if cell[:x1]==x && cell[:y1]==y
						cells_for_val=[]
						val=0
						#左隣
						unless (cell[:y1]...cell[:y2]).each{|dy|
							dcell=cells.find{|e|e[:x1]<=x-1&&x-1<e[:x2] && e[:y1]<=dy&&dy<e[:y2]}
							if !dcell||!cells_for_val.include?(dcell)
								cells_for_val.push(dcell) if dcell
								break if !m[dy][x-1] # まだセルが埋まっていなければスキップ。breakするとeachはnilを返す。unless〜next。
								val+=m[dy][x-1]
							end
						}
							next
						end
						#上隣
						unless (cell[:x1]...cell[:x2]).each{|dx|
							dcell=cells.find{|e|e[:x1]<=dx&&dx<e[:x2] && e[:y1]<=y-1&&y-1<e[:y2]}
							if !dcell||!cells_for_val.include?(dcell)
								cells_for_val.push(dcell) if dcell
								break if !m[y-1][dx]
								val+=m[y-1][dx]
							end
						}
							next
						end
						#セルを埋める
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
	end
	puts "%02d"%m[_y][_x]
end