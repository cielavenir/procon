#!/usr/bin/ruby
a,b,c=gets.split.map(&:to_i)
r=s=0
H=Hash.new{|h,k|h[k]=[]}
gets.to_i.times{
	x,y=gets.split
	H[y]<<x.to_i
}
H['USB'].sort!
a=H['USB'].size if a>H['USB'].size
r+=a
s+=H['USB'].shift(a).reduce(0,:+)
H['PS/2'].sort!
b=H['PS/2'].size if b>H['PS/2'].size
r+=b
s+=H['PS/2'].shift(b).reduce(0,:+)
q=(H['USB']+H['PS/2']).sort
c=q.size if c>q.size
r+=c
s+=q.shift(c).reduce(0,:+)
puts '%d %d'%[r,s]
