#!/usr/bin/ruby
s=gets.chomp
t=s[0...-1]
if s[0]=='0'||s[-1]=='1'||t!=t.reverse
	p -1
	exit
end
s[-1]='1'
q=[]
s.size.times{|i|q<<i if s[i]=='1'}
(s.size-1).times{|i|q.shift if i==q[0];puts [i+1,q[0]+1]*' '}
