#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/7c46e8409c456e8fabd1
#http://nabetani.sakura.ne.jp/hena/ord9nummake/
STDOUT.sync=true
while gets
	n,s=$_.chomp.split(':')
	n=n.to_i
	a=[]
	s=s.chars.group_by(&:to_i)
	s.default=[]
	1000.step(9999){|i|
		x=i.to_s.chars.group_by(&:to_i)
		x.default=[]
		if x.has_key?(9)
			x[6]+=x[9]
			x.delete(9)
		end
		if x.all?{|k,v|v.size<=s[k].size}
			n-=1
			if n==0
				p i
				break
			end
		end
	}
	puts '-' if n>0
end