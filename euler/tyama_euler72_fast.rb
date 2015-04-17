#!/usr/bin/ruby
N=1000001
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
gets.to_i.times{puts p[gets.to_i]-1}
__END__
1
1000000