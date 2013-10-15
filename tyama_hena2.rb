#!/usr/bin/env ruby
#http://nabetani.sakura.ne.jp/hena/ord2/
STDOUT.sync=true
while gets
	puts $_
		.split('-')
		.map{|e|f=e.to_i(16);8.times.map{|i|f[i]}}
		.transpose
		.delete_if{|e|e.all?{|f|f==1}}
		.transpose
		.map{|e|sprintf("%02x",e.map(&:to_s).join.reverse.to_i(2))}*'-'
end