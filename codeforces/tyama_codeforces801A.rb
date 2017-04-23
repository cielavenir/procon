#!/usr/bin/ruby
s=gets.chomp
r=s.scan('VK').size
s.size.times{|i|
	s[i]=s[i].tr('VK','KV')
	r=[r,s.scan('VK').size].max
	s[i]=s[i].tr('VK','KV')
}
p r
