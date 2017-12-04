#!/usr/bin/env ruby
#https://qiita.com/Nabetani/items/de5b9d3230603033ed74
#http://nabetani.sakura.ne.jp/hena/ordf07chairs/
STDOUT.sync=true
while gets
	a=$_.chomp
	chairs=Array.new(9)
	list={}
	a.chars{|e|
		if ('a'..'z').include?(e)
			chairs[list[e.upcase]]=nil
			list.delete(e.upcase)
		else
			seq=[0,8,1,7,2,6,3,5,4]
			seq.reverse! if e>='N'
			x=seq.map.with_index{|i,j|
				if chairs[i]
					[999,j,i]
				else
					[(chairs[(i-1)%9]?0:-1)+(chairs[(i+1)%9]?0:-1),j,i]
				end
			}.min
			chairs[x.last]=e
			list[e]=x.last
		end
	}
	puts chairs.map{|e|e ? e : '-'}*''
end
