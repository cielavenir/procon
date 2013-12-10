#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/6a9f5593d0f3d7e0568c
#http://nabetani.sakura.ne.jp/hena/ord16boseg/
STDOUT.sync=true
while gets
	a=[0]*7
	#b=('%036b'%$_.to_i(8)).split('').each_slice(6).to_a
	b=$_.scan(/../).map{|e|('%06b'%e.to_i(8)).split('')}
	[b,b.transpose].each{|l|
		0.step(4){|y|0.step(5).map{|x|l[y][x]!=l[y+1][x] ? '1' : ' '}.join.split.each{|e|a[e.size]+=1}}
	}
	puts a[1,6]*','
end