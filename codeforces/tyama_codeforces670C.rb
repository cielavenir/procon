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
b=Counter(gets.split.map(&:to_i))
m=gets.to_i
p gets.split.map(&:to_i).zip(gets.split.map(&:to_i)).each_with_index.map{|(k,l),z|[b[k],b[l],z+1]}.max[2]
