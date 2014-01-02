#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/dabe8ec57e0313229552
#http://nabetani.sakura.ne.jp/hena/ord17scheherazade/
STDOUT.sync=true
while gets
	n=$_.to_i
	puts n<3 ? '-' : ((2..(n-1)/2).select{|i|
		n0=n
		n1=0
		while n0>0
			n1=n1*i+n0%i
			n0/=i
		end
		n1==n
	}+[n-1])*','
end