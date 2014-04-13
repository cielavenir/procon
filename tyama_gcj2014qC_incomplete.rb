#!/usr/bin/ruby
gets.to_i.times{|i|
	puts "Case ##{i+1}:"
	row,col,mines=gets.split.map(&:to_i)
	area=row*col-mines
	if area==0
		puts 'Impossible'
	elsif row==1
		puts 'c'+'.'*(area-1)+'*'*mines
	elsif col==1
		puts 'c'
		(area-1).times{puts '.'}
		mines.times{puts '*'}
	else
		area_row=2
		while area_row<=row
			mod=area%area_row
			area_col=area/area_row
			area_col2=area_col+(mod==0 ? 0 : 1)
			p [area,area_row,mod,area_col2]
			break if mod!=1 && 1<area_col2 && area_col2<=col
			area_row+=1
		end
		if area_row>row
			#not good for sparse input like "4 7 3"
			puts 'Impossible'
		else
			r=row.times.map{['*']*col}
			area_row.times{|i|
				area_col.times{|j|
					r[i][j]='.'
				}
			}
			mod.times{|i|
				r[i][area_col]='.'
			}
			r[0][0]='c'
			r.each{|e|puts e*''}
		end
	end
}