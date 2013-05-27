#!/usr/bin/ruby
a=$<.map(&:chomp)
s=a[0].size
a=a[0...1<<s]
prev=0
toggle=0
h={}
a.each{|e|
	n=e.to_i(2)
	raise if h[n] #resend
	h[n]=1
	toggle+=s.times.count{|i|n[i]!=prev[i]}
	prev=n
}
raise if h.size!=1<<s
p toggle