#!/usr/bin/ruby
#https://github.com/DRMacIver/Feedback-Arc-Set
FAS='fas'

N=gets.to_i
data=$<.read
r=0
order=''
100.times{
	IO.popen(FAS,'r+'){|io|
		io.puts N
		io.puts data
		io.close_write
		n=io.gets.partition(': ')[2].to_i
		tmp_order=io.gets.partition(': ')[2].tr('[]','')
		if r<n
			r=n
			order=tmp_order
		end
	}
}
p r
puts order