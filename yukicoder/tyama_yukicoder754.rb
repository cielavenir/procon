#!/usr/bin/ruby
M=10**9+7;n,*a=`dd`.split.map &:to_i;b=a.pop(n+1)
s=0
c=b.reduce :+
a.each_with_index{|e,i|s=(s+e*c)%(10**9+7);c-=b[n-i]}
p s
__END__
3 + 2x + 2x2
7 + 0x + 4x2
-> 21 + 14x + 36x
