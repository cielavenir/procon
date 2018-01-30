#!/usr/bin/ruby

def is_minimam(a1,b1,a2,b2,a3,b3)
	(a2-a1)*(b3-b2)>=(b2-b1)*(a3-a2)
end
def is_maximam(a1,b1,a2,b2,a3,b3)
	is_minimam(-a1,-b1,-a2,-b2,-a3,-b3)
end
def check(l1,l2,l3)
	is_minimam(l1[0],l1[1],l2[0],l2[1],l3[0],l3[1])
end
def calc(l,now)
	l[0]*now+l[1]
end

class ConvexHullTrick
	def initialize
		@deque=[]
		@s=0
		@t=0
	end
	def add(a,b)
		l=[a,b]
		while @s+1<@t&&check(@deque[@t-2]||[0,0],@deque[@t-1]||[0,0],l)
			@t-=1
		end
		@deque[@t]=l
		@t+=1
	end
	def get(now)
		while @s+1<@t&&calc(@deque[@s]||[0,0],now)>=calc(@deque[@s+1]||[0,0],now)
			@s+=1
		end
		calc(@deque[@s],now)
	end
end

n,*a=`dd`.split.map(&:to_i)
deq=ConvexHullTrick.new
n.times{|j|deq.add(-2*j,a[j]+j*j)}
n.times{|i|p i*i+deq.get(i)}
