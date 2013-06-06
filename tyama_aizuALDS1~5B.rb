#!/usr/bin/ruby
$c=0
def merge(a,left,mid,right)
	n1=mid-left
	n2=right-mid
	l=a[left,n1]
	r=a[mid,n2]
	l<<999999999
	r<<999999999
	i=0
	j=0
	left.step(right-1){|k|
		$c+=1
		if l[i]<=r[j]
			a[k]=l[i]
			i=i+1
		else
			a[k]=r[j]
			j=j+1
		end
	}
end
def mergesort(a,left,right)
	if left+1<right
		mid=(left+right)/2
		mergesort(a,left,mid)
		mergesort(a,mid,right)
		merge(a,left,mid,right)
	end
end
gets;a=gets.split.map(&:to_i)
mergesort(a,0,a.size)
puts a*' '
p $c