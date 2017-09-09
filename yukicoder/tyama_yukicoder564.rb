#!/usr/bin/ruby
x,n,*a=`dd`.split.map &:to_i
n=(a<<x).sort_by(&:-@).index(x)
print n+1,n%10==0?:st:n%10==1?:nd:n%10==2?:rd: :th
