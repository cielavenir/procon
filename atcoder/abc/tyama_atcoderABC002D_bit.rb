#!/usr/bin/ruby
$h={}
$n,m=gets.split.map(&:to_i)
m.times{
	$h[gets.split.map{|e|e.to_i-1}]=1
}

$max=1
(1<<$n).times{|i|
	a=$n.times.select{|e|i[e]==1} #bits
	if a.size.times{|j|
		break unless (j+1).step(a.size-1){|k|break unless $h[[a[j],a[k]]]}
	} then $max=[a.size,$max].max end
}
p $max