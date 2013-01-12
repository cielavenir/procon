#!/usr/bin/ruby
while gets
m=0
s=nil
a=$_.chomp.split('')
0.step(a.size-2){|i|
	b=a[i..-1]
	1.step(b.size/2){|j|
		c=b.each_cons(j).to_a.map(&:join)
		t=c.shift
		l=c.select{|e|e==t}.count
		if l>0&&m<(l+1)*t.size then m=(l+1)*t.size;s=t end
	}
}
puts s&&s!=' '?s:'NONE'
end