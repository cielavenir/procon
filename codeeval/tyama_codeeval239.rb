#!/usr/bin/ruby
def partition(a,p,r)
	x=a[p]
	i=r
	r.downto(p+1){|j|
		if a[j]>=x
			a[i],a[j]=a[j],a[i]
			i=i-1
		end
	}
	a[i],a[p]=a[p],a[i]
	return i
end
def quicksort(a,p,r)
	if p<r
		$cnt+=1
		q=partition(a,p,r)
		quicksort(a,p,q-1)
		quicksort(a,q+1,r)
	end
end
$<.each{|_|
	a=_.split.map(&:to_i)
	$cnt=0
	quicksort(a,0,a.size-1)
	p $cnt
}