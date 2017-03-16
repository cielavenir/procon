#!/usr/bin/ruby
n,q,*x=`dd`.split.map &:to_i;z=x.pop q;s=0,*x;1.upto(n){|i|s[i]+=s[i-1]}
z.map{|t|m=(0...n).bsearch{|i|x[i]>=t}||n;p t*(2*m-n)-2*s[m]+s[n]}
__END__
m*t-s[m]+(s[n+1]-s[m])-(n-m)*t
