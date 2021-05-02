#!/usr/bin/ruby
$memo={}
def dfs(k,idx)
	$memo[[k,idx]]||=->{
		r=S[idx..-1].to_i
		if k==0
			r
		else
			(idx+[1,L-1].max ... [S.size,idx+L+1].min).each{|i|
				r=[r,[S[idx...i].to_i,dfs(k-1,i)].max].min
			}
			r
		end
	}.()
end

K=gets.to_i
S=gets.chomp
L=(S.size+K)/(K+1)
raise if S.size>100 # 2000
p dfs(K,0)
