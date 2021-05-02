#!/usr/bin/ruby
class Counter < Hash
	def initialize(a=[])
		super
		self.default=0
		a.each{|e|self[e]+=1}
	end
	def most_common(n=nil)
		a=self.sort_by{|k,v|v}.reverse
		a=a[0,n] if n
		a
	end
	def self.[](*a)
		new(a)
	end
end
def Counter(a=[]) Counter.new(a) end
 
n,*v=`dd`.split.map &:to_i
v=v.each_slice(2).to_a
a,b=v.shift.zip(*v).map(&:compact).map{|e|Counter(e).most_common<<[0,0]}
if a[0][0] != b[0][0]
	p n - (a[0][1] + b[0][1])
else
	p [n-(a[1][1]+b[0][1]), n-(a[0][1]+b[1][1])].min
end
