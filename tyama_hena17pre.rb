#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/dabe8ec57e0313229552
#http://nabetani.sakura.ne.jp/hena/ord17scheherazade/
STDOUT.sync=true
while gets
	n=$_.to_i
	puts n<3 ? '-' : (2.step((n-1)/2).select{|i|
		n0=n
		a=[]
		while n0>0
			a<<n0%i
			n0/=i
		end
		a==a.reverse
	}+[n-1])*','
end