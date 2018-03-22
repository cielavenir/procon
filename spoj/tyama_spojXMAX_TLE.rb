#!/usr/bin/ruby
B=62
def solve(a)
	idx=0
	(B-1).downto(0){|i|
		maxI=idx
		maxE=-1
		(idx...a.size).each{|j|
			if a[j][i]>0 && a[j]>maxE
				maxE=a[j]
				maxI=j
			end
		}
		next if maxE<0
		a[idx],a[maxI]=a[maxI],a[idx]
		maxI=idx
		a.size.times{|j|
			if j!=maxI && a[j][i]>0
				a[j]=a[j]^a[maxI]
			end
		}
		idx+=1
	}
	a.reduce(:^)
end
n,*a=$<.read.split.map(&:to_i)
p solve(a)
