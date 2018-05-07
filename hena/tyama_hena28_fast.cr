#!/usr/bin/env crystal
#http://qiita.com/Nabetani/items/23ebddb44f0234e7fb15
#http://nabetani.sakura.ne.jp/hena/ord28spirwa/

dir="ESWN"
while l_=gets
	line=l_.chomp.split(':')
	n,e,s,w=line[0].split(',').map(&.to_i64)
	l=[e,s,w,n]
	days=line[1].to_i64+1
	(0..1/0.0).each{|i|
		[
			l[i%4]+(i%4==0 ? 1 : 0),
			(i/4+1)*2,
			l[i%4]-(i%4==3 ? 1 : 0),
		].each_with_index{|e,j|
			days-=e
			if days<0
				puts dir[(i+j)%4]
				break
			end
		}
		break if days<0
	}
	STDOUT.flush
end
