#!/usr/bin/ruby
require 'prime'
class String
	def pan?
		if self.size!=$n then return false end
		return 1.step(self.size).all?{|i|self.index(i.to_s)} ? true : false
	end
end
h={}
$n=gets.to_i
1.step(1000){|i|1.step(10000/i){|j|k=i*j;if [i,j,k].map(&:to_s).join.pan? then h[k]=1 end}}
p h.keys.reduce(0,:+)

__END__
9