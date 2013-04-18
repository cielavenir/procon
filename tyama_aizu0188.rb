#!/usr/bin/ruby
$c=0
def binary(a,v)
	left=0;right=a.length-1
	while left<=right
		$c+=1
		center=(left+right)/2
		if a[center]==v then return v end
		if a[center]>v then right=center-1 else left=center+1 end
	end
	return nil
end
while(n=gets.to_i)>0
	a=n.times.map{gets.to_i}
	$c=0;binary(a,gets.to_i);p $c
end