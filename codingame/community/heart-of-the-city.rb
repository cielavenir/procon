#!/usr/bin/ruby
#utilize farey sequence
N=(gets.to_i+1)/2
t=[false]*N
p=[*0...N]
2.step(N-1){|i|
	if !t[i]
		i.step(N-1,i){|j|
			t[j]=true
			p[j]-=p[j]/i
		}
	end
}
1.step(N-1){|i|p[i]+=p[i-1]}
puts p[N-1]*8