#!/usr/bin/env ruby
#http://nabetani.sakura.ne.jp/yokohamarb/2014.10.rotcell/
#http://qiita.com/Nabetani/items/d6ac6695787e76758a18
if RUBY_VERSION<'1.9'
	require 'rubygems'
	require 'backports' # (Math.cbrtと異なり)1.8のArray#rotateはbackportsに存在するので、ありがたく使わせて頂きます
end

if $0==__FILE__
	STDOUT.sync=true
	while gets
		str=[]
		area=[*'a'..'y'].each_slice(5).to_a
		grid=[*0...area[0].size].product([*0...area.size])
		$_.chomp.each_char{|_c|
			c=_c.downcase
			f=c==_c ? -1 : 1
			x,y=grid.find{|x,y|area[y][x]==c}
			minx,maxx=[x-1,x+1]
			miny,maxy=[y-1,y+1]
			x=minx
			y=miny
			rotaters=[]
			rotaters<<[x+=1,y] while x<maxx
			rotaters<<[x,y+=1] while y<maxy
			rotaters<<[x-=1,y] while x>minx
			rotaters<<[x,y-=1] while y>miny
			rotaters=rotaters.select{|x,y|0<=y&&y<area.size && 0<=x&&x<area[y].size}
			str=rotaters.map{|x,y|area[y][x]}.rotate(f)
			rotaters.each_with_index{|(x,y),i|area[y][x]=str[i]}
		}
		puts str.sort*''
	end
end