#!/usr/bin/ruby
r,_,t,*a=`dd`.split.map &:to_i;m=0;a.map{|e|t>e&&t=e;m,r=e,0if m<e-=t;r+=1[m-e]};p r

__END__
n,t,*a=`dd`.split.map(&:to_i)
amin=[a[0]]
1.upto(a.size-1){|i|amin[i]=[amin[i-1],a[i]].min}
amax=[]
amax[a.size-1]=a[-1]
(a.size-2).downto(0){|i|amax[i]=[amax[i+1],a[i]].max}
r=amax.zip(amin).uniq.map{|x,y|y-x}.sort
p r.take_while{|e|e==r[0]}.size
