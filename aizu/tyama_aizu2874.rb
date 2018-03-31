#!/usr/bin/ruby
n,*a=$<.read.split.map &:to_i
n.times{|i|
	(i+1...n).each{|j|
		if (a[i]-a[j])%~-n==0
			puts '%d %d'%[a[i],a[j]]
			exit
		end
	}
}

