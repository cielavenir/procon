#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/636fce060e1ebbc95f9b
#http://nabetani.sakura.ne.jp/hena/ord25rotcell/
if RUBY_VERSION<'1.9'
	require 'rubygems'
	require 'backports' # (Math.cbrtと異なり)1.8のArray#rotateはbackportsに存在するので、ありがたく使わせて頂きます
end
if $0==__FILE__
	STDOUT.sync=true
	while gets
		str=''
		area=[*'a'..'y'].each_slice(5).to_a
		$_.chomp.split(',').each{|s|
			x,y=2.times.map{|i|[*0...area[0].size].product([*0...area.size]).find{|x,y|area[y][x]==s[i,1]}}.transpose
			minx,maxx=x.minmax.zip([-1,1]).map{|e|e.reduce(:+)}
			miny,maxy=y.minmax.zip([-1,1]).map{|e|e.reduce(:+)}
			x=minx
			y=miny
			rotaters=[]
			rotaters<<[x+=1,y] while x<maxx
			rotaters<<[x,y+=1] while y<maxy
			rotaters<<[x-=1,y] while x>minx
			rotaters<<[x,y-=1] while y>miny
			rotaters=rotaters.select{|x,y|0<=y&&y<area.size && 0<=x&&x<area[y].size}
			str=rotaters.map{|x,y|area[y][x]}.rotate(-1)
			rotaters.each_with_index{|(x,y),i|area[y][x]=str[i]}
		}
		puts str.empty? ? :none : str.sort*''
	end
end