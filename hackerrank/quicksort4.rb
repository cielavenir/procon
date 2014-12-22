#!/usr/bin/ruby
$ins=0
def insertion(a)
	1.step(a.size-1){|i|
		t=a[i]
		if a[i-1]>t
			j=i
			begin
				a[j]=a[j-1]
				$ins=$ins+=1
				j=j-1
			end while j>0&&a[j-1]>t
			a[j]=t
		end
	}
end
$quick=0
def partition(a,p,r)
	x=a[r]
	i=p
	p.step(r-1){|j|
		if a[j]<=x
			a[i],a[j]=a[j],a[i]
			$quick=$quick+1
			i=i+1
		end
	}
	a[i],a[r]=a[r],a[i]
	$quick=$quick+1
	return i
end
def quicksort(a,p,r)
	if p<r
		q=partition(a,p,r)
		quicksort(a,p,q-1)
		quicksort(a,q+1,r)
	end
end

gets
a=gets.split.map(&:to_i)
insertion(a.dup)
quicksort(a,0,a.size-1)
p $ins-$quick