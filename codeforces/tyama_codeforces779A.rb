#!/usr/bin/ruby
class Counter < Hash
	def initialize(a=[])
		super
		self.default=0
		a.each{|e|self[e]+=1}
	end
	def self.[](*a)
		new(a)
	end
end
def Counter(a=[]) Counter.new(a) end

n=gets.to_i
a=Counter(gets.split.map &:to_i)
b=Counter(gets.split.map &:to_i)
r=0
p (1..5).all?{|i|
	(a[i]+b[i])%2<1 && r+=(a[i]-b[i]).abs/2
} ? r/2 : -1
