#!/usr/bin/ruby
require'prime'
n,m=gets.split.map &:to_i
k=m.prime_division.map{|x,p|r=0;y=n;r+=y/=x while y>0;r/p}.min
r=Math.lgamma(n+1)[0]/Math.log(10)-k*Math.log10(m)
x=(10**(r+3-z=r.to_i)).to_i
puts'%fe%d'%[x/1000.0,z]

__END__
t=[0]*1000+(1000..10000).map{|i|Math.log10(i)}
z=r.to_i
r-=z-3
x=(0..10000).bsearch{|i|t[i]>r}-1
puts '%d.%03de%d'%[x/1000,x%1000,z]
