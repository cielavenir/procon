#!/usr/bin/ruby
#require 'prime'
def prime_division(n)
	IO.popen('factor','r+b'){|io|
		io.puts n
		io.close_write
		io.gets.split[1..-1]
	}
end
gets.to_i.times{|i|
	puts "Case ##{i+1}:"
	n,j=gets.split.map(&:to_i)
	(1<<(n-2)).times{|x|
		x=( (1<<(n-1))|(x<<1)|1 ).to_s(2)
		a=(2..10).map{|i|prime_division x.to_i(i)}
		if a.none?{|e|e.size==1}
			print x,' '
			puts a.map{|e|e[0]}*' '
			j-=1
			break if j==0
		end
	}
}