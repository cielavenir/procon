#!/usr/bin/ruby
n,k=gets.split.map(&:to_i)
s=gets.chomp.split('')
t=s.sort
n.times{|i|
	i.step(n-1){|j|
		r=t[i...j]+t[j+1..-1]
		s[i+1..-1].each{|e|(idx=r.index(e)) && r.delete_at(idx)}
		f=s[i]!=t[j] ? 1 : 0
		if r.size+f<=k
			k-=f
			t[i],t[j]=t[j],t[i]
			t=t[0..i]+t[i+1..-1].sort
			break
		end
	}
}
puts t*''