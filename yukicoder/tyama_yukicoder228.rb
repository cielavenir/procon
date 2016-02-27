#!/usr/bin/ruby
def perm
	r=0
	A.size.times{|i|
		(i+1..A.size-1).each{|j|
			r+=1 if A[i]>A[j]
		}
	}
	r
end
a=$<.map{|e|e.split.map(&:to_i)}
A=[]
ds=0
d0=0
parity=nil
4.times{|y|4.times{|x|
	k=a[y][x]
	if k>0
		A<<k
		k-=1
		ty,tx=k.divmod(4)
		d=(y-ty).abs+(x-tx).abs
		ds+=d
		if d>1
			puts :No
			exit
		end
	else
		tx=ty=3
		parity=(y-ty).abs
		d0=(y-ty).abs+(x-tx).abs
	end
}}
if (ds==0)!=(d0==0)
	puts :No
	exit
end
puts [:Yes,:No][(perm+parity)%2]