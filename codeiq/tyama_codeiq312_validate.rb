#!/usr/bin/ruby
a=$<.map(&:chomp)
s=a[0].size
a=a[0...1<<s]
prev=0
toggle=0
h={}
a.each{|e|
	raise "too many chars #{e}" if e.size>s
	n=e.to_i(2)
	raise "resend #{e}" if h[n]
	h[n]=1
	toggle+=s.times.count{|i|n[i]!=prev[i]}
	prev=n
}
raise "line number wrong #{h.size}" if h.size!=1<<s
raise "#{prev.to_i(2)}: not ending with #{'0'*s}" if prev!=0
p toggle