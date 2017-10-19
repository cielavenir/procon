#!/usr/bin/ruby
gets;$<.map{|e|a,b=e.split.map &:to_i;r=Math.log10(a)*b;x=(10**(r+1-z=r.to_i)).to_i;puts'%d %d %d'%[x/10,x%10,z]}

__END__
t=[0]*10+(10..100).map{|i|Math.log10(i)}
gets.to_i.times{
	a,b=gets.split.map &:to_i
	r=Math.log10(a)*b
	z=r.to_i
	r-=z-1
	x=(0..100).bsearch{|i|t[i]>r}-1
	puts'%d %d %d'%[x/10,x%10,z]
}
