#!/usr/bin/ruby
class Card
	attr_reader :n, :s
	def initialize(s,n)
		@s=s;@n=n
	end
	def <=(o)
		@n<=o.n
	end
	def ==(o)
		@s==o.s&&@n==o.n
	end
	def to_s
		@s+' '+@n.to_s
	end
end
def partition(a,p,r)
	x=a[r]
	i=p
	p.step(r-1){|j|
		if a[j]<=x
			a[i],a[j]=a[j],a[i]
			i=i+1
		end
	}
	a[i],a[r]=a[r],a[i]
	return i
end
def quicksort(a,p,r)
	if p<r
		q=partition(a,p,r)
		quicksort(a,p,q-1)
		quicksort(a,q+1,r)
	end
end
def merge(a,left,mid,right)
	n1=mid-left
	n2=right-mid
	l=a[left,n1]
	r=a[mid,n2]
	l<<Card.new('',9999999999)
	r<<Card.new('',9999999999)
	i=0
	j=0
	left.step(right-1){|k|
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
a=$<.drop(1).map(&:split)
card=[];card2=[]
a.each{|e|card<<Card.new(e[0],e[1].to_i);card2<<Card.new(e[0],e[1].to_i)}
quicksort(card,0,card.size-1)
mergesort(card2,0,card2.size)
puts card==card2 ? 'Stable' : 'Not stable'
puts card