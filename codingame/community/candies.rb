#!/usr/bin/ruby
N,K=gets.split.map(&:to_i)
def dfs(n,a)
	if n==0
		puts a*' '
	else
		(1..[K,n].min).each{|j|
			dfs(n-j,a+[j])
		}
	end
end
dfs(N,[])
__END__
r=[1]+[0]*N
1.upto(N){|i|
	(1..[K,N].min).each{|j|
		r[i]+=r[i-j]
	}
}
p r[-1]