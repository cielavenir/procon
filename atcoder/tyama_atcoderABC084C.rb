#!/usr/bin/ruby
n=gets.to_i
c,s,f=$<.map{|e|e.split.map &:to_i}.transpose
n.times{|i|
	t=0
	(i..n-2).each{|j|
		if t<s[j]
			t=s[j]
		elsif t%f[j]!=0
			t+=f[j]-t%f[j]
		end
		t+=c[j]
	}
	p t
}
