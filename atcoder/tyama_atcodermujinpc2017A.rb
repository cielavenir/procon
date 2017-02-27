#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i;c=0
0.upto(n-g=r=1){|i|g>a[i]?r*=i+2-c+=1:g+=2}
1.upto(n-c){|i|r=r*i%(10**9+7)};p r
