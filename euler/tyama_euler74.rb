#!/usr/bin/ruby
$h={}
class Integer
	def chain() self.to_s.chars.reduce(0){|s,e|s+$h[e.to_i]} end
end
10.times{|i|$h[i]=(2..i).reduce(1,:*)}

gets.to_i.times{
$r={}
x=[]
M,N=gets.split.map(&:to_i)
0.step(M){|i|
	if $r[i]
		x<<i if $r[i]==N 
		next
	end
	a=[]
	r=i
	begin
		a<<r
		r=r.chain
	end while !(idx=a.index(r)) &&!$r[r]
	a.size.times{|j|
		if a[j]<=M
			$r[a[j]] = $r[r] ? a.size-j+$r[r] : j>=idx ? a.size-idx : a.size-j
		end
	}
	x<<i if $r[i]==N 
}
puts x.empty? ? -1 : x*' '
p $r
}
__END__
1
999999 60