#!/usr/bin/ruby
#剰余は環をなすため、貪欲法で解いて問題ない。

puts $<.map{|e|
	a,b=e.split
	c=j=0
	a.bytes{|x|
		c=(c+x-48)%10
		c.to_s==b[j,1]&&(j+=1;c=0)
	}
	b.size-j+c==0?:YES: :NO
}