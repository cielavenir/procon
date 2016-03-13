#!/usr/bin/ruby
def partition(a,p,r)
	i,j,k=p,r,a[p]

	loop{
    	i+=1 while a[i]<k
		j-=1 while a[j]>k
		if i>=j
			return j
		else
			a[i],a[j]=a[j],a[i]
		end
	}
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