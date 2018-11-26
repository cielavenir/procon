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

n,k,*a=$<.read.split.map &:to_i
c=Counter(a)
p -c.values.max/k*-k*c.size-n
