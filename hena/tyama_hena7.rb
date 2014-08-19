#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/4364285801d1c9f370a1
#http://nabetani.sakura.ne.jp/hena/ord7selectchair/
STDOUT.sync=true
while gets
	a=$_.chomp.split(':')
	n=a[0].to_i
	chairs=Array.new(n+2)
	list={}
	a[1].chars{|e|
		if ('a'..'z').include?(e)
			chairs[list[e.upcase]]=nil
			list.delete(e.upcase)
		else
			x=1.step(n).map{|i|
				if chairs[i]
					[999,i]
				else
					[(chairs[i-1]?0:-1)+(chairs[i+1]?0:-1),i]
				end
			}.min
			chairs[x.last]=e
			list[e]=x.last
		end
	}
	puts chairs[1..n].map{|e|e ? e : '-'}*''
end