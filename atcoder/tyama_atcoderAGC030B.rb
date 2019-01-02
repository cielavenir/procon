#!/usr/bin/ruby
L,N,*x=`dd`.split.map &:to_i
y=[r=0]+x.map{|e|L-e}.reverse
x=[0]+x
sx=[0]
sy=[0]
N.times{|i|sx<<sx[i]+x[i+1];sy<<sy[i]+y[i+1]}
N.times{|i|
	j=N-i
	k=[i,j-1].min
	r=[
		r,
		x[i+1]+2*(sx[i]-sx[i-k]+sy[j-1]-sy[j-k-1-(j-1>k ? 1 : 0)]),
		y[j]+2*(sx[i]-sx[i-k-(i>k ? 1 : 0)]+sy[j-1]-sy[j-k-1])
	].max
}
p r
