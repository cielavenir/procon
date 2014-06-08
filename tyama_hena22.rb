#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/34bf2a05099a47e193b6
#http://nabetani.sakura.ne.jp/hena/ord22irrpas/
STDOUT.sync=true
while gets
	a,b=$_.chomp.split(':')
	column,row=a.split('x').map(&:to_i)
	cells=!b ? [] : b.split(',').map{|e|
		l,t,w,h=e.split('').map(&:to_i)
		#番兵を設けるため1を足す。高さ/幅から端点の座標に変更。
		{:x1=>l.to_i+1,:x2=>l.to_i+1+w.to_i,:y1=>t.to_i+1,:y2=>t.to_i+1+h.to_i}
	}

	m=(row+1).times.map{[nil]*(column+1)}
	(row+1).times{|y|m[y][0]=0}
	(column+1).times{|x|m[0][x]=0}
	m[0][1]=1 #m[1][0]=1でも可。適当。

	while !m[row][column] # 右下が埋まるまで
		1.step(row){|y|
			1.step(column){|x|
				next if m[y][x] # 既に埋まっていたらスキップ
				#1x1のセルでなければ
				if cell=cells.find{|e|e[:x1]<=x&&x<e[:x2] && e[:y1]<=y&&y<e[:y2]}
					#セルの右上を見ている時に限り左・上隣を見る
					if cell[:x1]==x && cell[:y1]==y
						cells_for_val={}
						val=0
						#左隣
						unless (cell[:y1]...cell[:y2]).each{|_y|
							adjacent_cell=cells.find{|e|e[:x1]<=x-1&&x-1<e[:x2] && e[:y1]<=_y&&_y<e[:y2]}
							if !adjacent_cell||!cells_for_val.include?(adjacent_cell)
								cells_for_val[adjacent_cell]=1 if adjacent_cell
								break if !m[_y][x-1] # まだセルが埋まっていなければスキップ。breakするとeachはnilを返す。unless〜next。
								val+=m[_y][x-1]
							end
						}
							next
						end
						#上隣
						unless (cell[:x1]...cell[:x2]).each{|_x|
							adjacent_cell=cells.find{|e|e[:x1]<=_x&&_x<e[:x2] && e[:y1]<=y-1&&y-1<e[:y2]}
							if !adjacent_cell||!cells_for_val.include?(adjacent_cell)
								cells_for_val[adjacent_cell]=1 if adjacent_cell
								break if !m[y-1][_x]
								val+=m[y-1][_x]
							end
						}
							next
						end
						#セルを埋める
						(cell[:y1]...cell[:y2]).each{|_y|
							(cell[:x1]...cell[:x2]).each{|_x|
								m[_y][_x]=val%100
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
	puts "%02d"%m[row][column]
end