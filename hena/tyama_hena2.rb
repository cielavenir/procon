#!/usr/bin/env ruby
#http://nabetani.sakura.ne.jp/hena/ord2/
class Integer
	def bits(n) n.times.map{|i|self[i]} end
end
STDOUT.sync=true
while gets
	puts $_
		.split('-')
		.map{|e|e.to_i(16).bits(8)}
		.transpose
		.delete_if{|e|e==[1]*e.size}
		.transpose
		.map{|e|sprintf("%02x",e.map(&:to_s).join.reverse.to_i(2))}*'-'
end