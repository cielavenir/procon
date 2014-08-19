#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/6a9f5593d0f3d7e0568c
#http://nabetani.sakura.ne.jp/hena/ord16boseg/
STDOUT.sync=true
while gets
	a=$_.scan(/../).map{|e|e.to_i(8)}
	r=[0]*(a.size+1)
	[a,a.size.times.map{|e|a.size.times.reduce(0){|s,f|s+=a[f][e]<<f}}].each{|e|
		(a.size-1).times{|y|('%b'%[e[y]^e[y+1]]).split('0').each{|f|r[f.size]+=1}}
	}
	puts r[1,a.size]*','
end