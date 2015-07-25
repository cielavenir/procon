#!/usr/bin/ruby
M=100000
A=(1..M).map{|i|i*i}.reverse
def dfs(lst,n,last)
	#go greedy way (we don't care about sub-optimal possibility)
	if n==0
		#avoid building unexpected mirror
		puts lst.each_with_index.map{|e,i|((97+(2*i)%26).chr+(97+(2*i+1)%26).chr)*(e-1) + (97+(2*i)%26).chr}*''
		exit
	else
		last.step(A.size-1){|i|
			d,r=n.divmod(A[i])
			if d>0
				dfs(lst+[M-i]*d,r,i+1)
			end
		}
	end
end
N=gets.to_i
dfs([],N,0)