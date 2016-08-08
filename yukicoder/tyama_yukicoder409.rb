#!/usr/bin/ruby
#Rubyが制限時間内に終了するかのテストです
#解法の検証ができているわけではありません

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

n,a,b,w=gets.split.map(&:to_i)
deq=ConvexHullTrick.new
z = w + 0 * a + b * 0 * (0 - 1) / 2
deq.add( - 0 * b, z)
r = z - a * (n - 0) + b * (n - 0) * (n - 0 + 1) / 2
gets.split.each_with_index{|e,i|
	z = e.to_i - i * a + ( b * i * (i + 1)) / 2 + deq.get(i)
	deq.add( - (i + 1) * b , z + (i + 1) * a + ( b * (i + 1) * i) / 2)
	r = [r,z - a * (n -(i+1)) + b * (n - (i+1)) * (n - (i+1) + 1) / 2].min
}
p r