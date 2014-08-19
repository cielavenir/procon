#!/usr/bin/ruby
$h={}
$n,m=gets.split.map(&:to_i)
m.times{
	$h[gets.split.map{|e|e.to_i-1}]=1
}

$max=1
def dfs(a,cur)
	if a.size.times{|j|
		break unless (j+1).step(a.size-1){|k|break unless $h[[a[j],a[k]]]}
	} then $max=[a.size,$max].max end
	cur.step($n-1){|i|
		dfs(a+[i],i+1)
	}
end
dfs([],0)
p $max