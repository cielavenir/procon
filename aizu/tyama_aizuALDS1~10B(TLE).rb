#!/usr/bin/ruby
a=gets.to_i.times.map{gets.split.map(&:to_i)}
$r=9999999
def dfs(a,s,m)
	if a.length==1
		if $r>s then $r=s end
	end
	0.step(a.length-2){|i|
		b=a.dup
		b[i,2]=[[a[i][0],a[i+1][1]]]
		dfs(b,s+a[i][0]*a[i][1]*a[i+1][1],m+[i])
	}
end
dfs(a,0,[])
p $r