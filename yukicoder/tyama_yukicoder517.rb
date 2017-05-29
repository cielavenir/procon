#!/usr/bin/ruby
a,b=2.times.map{
	gets.to_i.times.map{gets.chomp}
}
prefix=a.map{|e|e[0]}&b.map{|e|e[0]}
(p -1;exit)if prefix.size>1
prefix=prefix[0]
s=a.find{|e|e[0]==prefix}
t=b.find{|e|e[0]==prefix}
while s.size!=t.size
	s+=a.find{|e|e[0]==t[s.size]} while s.size<t.size
	t+=b.find{|e|e[0]==s[t.size]} while s.size>t.size
end
puts s
