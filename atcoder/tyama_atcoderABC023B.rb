#!/usr/bin/ruby
gets
s=gets.chomp
x='b'
i=0
while x.size<s.size
	i+=1
	x='a'+x+'c' if i%3==1
	x='c'+x+'a' if i%3==2
	x='b'+x+'b' if i%3==0
end
p x==s ? i : -1