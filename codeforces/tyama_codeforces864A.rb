#!/usr/bin/ruby
n,*a=$<.read.split.map &:to_i
a.sort!
if a.count(a[0])==a.size/2 && a.count(a[-1])==a.size/2
	puts "YES\n%d %d"%[a[0],a[-1]]
else
	puts :NO
end
