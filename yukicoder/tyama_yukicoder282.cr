#!/usr/bin/env crystal
def perform(start,q)
	puts "? "+q.join(" ")
	STDOUT.flush
	f=true
	gets.not_nil!.split.each_with_index(0){|e,i|
		if e==">"
			f=false
			A.swap(i*2+0+start,i*2+1+start)
		end
	}
	f	
end
def g(s,e,pad) A[s...e].each_slice(2).flat_map{|e|e}.to_a+[0]*pad end

N=gets.not_nil!.to_i
A=(1..N).to_a
loop{break if perform(0,N%2==0?g(0,N,N) : g(0,N-1,N+1)) || perform(1,N%2==0?g(1,N-1,N+2) : g(1,N,N+1))}
puts "! "+A.join(" ")
