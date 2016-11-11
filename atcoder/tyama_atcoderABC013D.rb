#!/usr/bin/ruby
#cf: AGC006C
n,m,k,*z=`dd`.split.map &:to_i
t=*1..n
*e=t
z.reverse.map{|x|t[x-1,2]=t[x],t[x-1]}
f=->q{t[q-1]};60.times{|i|k[i]>0&&e.map!(&f);t=t.map &f}
p *e
