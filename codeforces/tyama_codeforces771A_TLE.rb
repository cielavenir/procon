#!/usr/bin/ruby
n,m=gets.split.map &:to_i
$h=Hash.new{|h,k|h[k]=[]}
$v={}
m.times{
	a,b=gets.split.map &:to_i
	$h[a-1]<<b-1
	$h[b-1]<<a-1
}
puts n.times.all?{|i|
	next true if $v[i]
	$v[i]=1
	v={i=>1}
	e={}
	q=[i]
	while !q.empty?
		c=q.shift
		$h[c].each{|x|
			z=[c,x].sort
			e[z]=1
			if !$v.include?(x)
				$v[x]=v[x]=1
				q<<x
			end
		}
	end
	e.size==v.size*(v.size-1)/2
} ? :YES : :NO
