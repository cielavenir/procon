#!/usr/bin/env crystal
def perform(q,start)
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
N=gets.not_nil!.to_i
A=(1..N).to_a
f=true
while f
	q=N%2==0 ? A[0...N].each_slice(2).flat_map{|e|e}+[0]*N : A[0...N-1].each_slice(2).flat_map{|e|e}+[0]*(N+1)
	break if perform(q,0)
	q=N%2==0 ? A[1...N-1].each_slice(2).flat_map{|e|e}+[0]*(N+2) : A[1...N].each_slice(2).flat_map{|e|e}+[0]*(N+1)
	break if perform(q,1)
end
puts "! "+A.join(" ")