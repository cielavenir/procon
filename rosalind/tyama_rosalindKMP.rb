#!/usr/bin/ruby
s=gets.chomp
a=[0]
k=0
1.step(s.size-1){|i|
	k=a[k-1] while k>0&&s[i]!=s[k]
	k+=1 if s[i]==s[k]
	a<<k
}
puts a*' '