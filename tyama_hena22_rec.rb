#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/34bf2a05099a47e193b6
#http://nabetani.sakura.ne.jp/hena/ord22irrpas/
class Hena22
	def initialize(cells)
		@cells=cells
		@memo={}
	end
	def solve(x,y)
		return 0 if x<0||y<0
		return 1 if x==0&&y==0
		if @memo[[x,y]]
			return @memo[[x,y]]
		end
		cell=@cells.find{|e|e[:x1]<=x&&x<e[:x2] && e[:y1]<=y&&y<e[:y2]}
		if cell
			if cell[:x1]==x && cell[:y1]==y
				cells_for_val={}
				val=0
				(cell[:y1]...cell[:y2]).each{|_y|
					adjacent_cell=@cells.find{|e|e[:x1]<=x-1&&x-1<e[:x2] && e[:y1]<=_y&&_y<e[:y2]}
					if !adjacent_cell||!cells_for_val.include?(adjacent_cell)
						cells_for_val[adjacent_cell]=1 if adjacent_cell
						val+=solve(x-1,_y)
					end
				}
				(cell[:x1]...cell[:x2]).each{|_x|
					adjacent_cell=@cells.find{|e|e[:x1]<=_x&&_x<e[:x2] && e[:y1]<=y-1&&y-1<e[:y2]}
					if !adjacent_cell||!cells_for_val.include?(adjacent_cell)
						cells_for_val[adjacent_cell]=1 if adjacent_cell
						val+=solve(_x,y-1)
					end
				}
				return @memo[[x,y]]=val
			else
				return @memo[[x,y]]=solve(cell[:x1],cell[:y1])
			end
		else
			return @memo[[x,y]]=solve(x-1,y)+solve(x,y-1)
		end
	end
end

if $0==__FILE__
	STDOUT.sync=true
	while gets
		a,b=$_.chomp.split(':')
		column,row=a.split('x').map(&:to_i)
		cells=!b ? [] : b.split(',').map{|e|
			l,t,w,h=e.split('').map(&:to_i)
			#高さ/幅から端点の座標に変更
			{:x1=>l.to_i,:x2=>l.to_i+w.to_i,:y1=>t.to_i,:y2=>t.to_i+h.to_i}
		}
		puts '%02d'%[Hena22.new(cells).solve(column-1,row-1)%100]
	end
end