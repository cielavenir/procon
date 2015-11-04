#!/usr/bin/ruby
#coding:utf-8
h=Hash.new(0)
gets.chomp.bytes{|c|h[c]+=1}
n=0
f=true
while f
	f=false
	[[48,57],[97,122]].each{|start,stop|
		(start..stop).each{|i|
			j=i
			j+=1 while j<=stop&&h[j]>0
			if j-i>3
				f=true
				while i<j
					h[i]-=1
					i+=1
				end
				n+=1
				break
			end
		}
	}
end
p n*3+h.values.reduce(:+)