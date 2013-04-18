#!/usr/bin/ruby
$h={}
class Integer
	def chain() self.to_s.chars.reduce(0){|s,e|s+=$h[e.to_i]} end
end
10.times{|i|$h[i]=(2..i).reduce(:*)||1}

$r={}
x=0
M=999999
N=60
1.step(M){|i|
	if $r[i]
		x+=1 if $r[i]==N 
		next
	end
	a=[]
	r=i
	begin
		a<<r
		r=r.chain
	end while !(idx=a.index(r)) &&!$r[r]
	a.length.times{|j|
		if a[j]<=M
			$r[a[j]] = $r[r] ? a.size-j+$r[r] : j>=idx ? a.size-idx : a.size-j
		end
	}
	x+=1 if $r[i]==N 
}
p x