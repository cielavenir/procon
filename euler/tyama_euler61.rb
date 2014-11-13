#!/usr/bin/ruby

T={
	3=>->(n){n*(n+1)/2},
	4=>->(n){n*n},
	5=>->(n){n*(3*n-1)/2},
	6=>->(n){n*(2*n-1)},
	7=>->(n){n*(5*n-3)/2},
	8=>->(n){n*(3*n-2)},
}
VAL=Hash[*T.each_key.flat_map{|e|[e,(1..1/0.0).take_while{|i|T[e][i]<10000}.drop_while{|i|T[e][i]<1000}.map{|i|T[e][i]}]}]

def dfs(a,d,cur,first,s,r)
	if d==a.size-1
		if cur%100==first/100
			yield r
		end
	else
		VAL[a[d]].each{|e|
			if cur%100==e/100
				dfs(a,d+1,e,first,s+e,r+[e]){|y|yield y}
			end
		}
	end
end

n=gets.to_i
a=gets.split.map(&:to_i)
ma=a.pop
result=[]
a.permutation{|_b|
	b=_b+[ma]
	VAL[ma].each{|e|
		dfs(b,0,e,e,e,[e]){|y|result << y}
	}
}
puts result.select{|e|e.uniq.size==n}.map{|e|e.reduce(:+)}.sort.uniq
__END__
6
3 4 5 6 7 8