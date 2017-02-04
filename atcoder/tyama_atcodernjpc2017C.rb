#!/usr/bin/ruby
n,l,r,*a=`dd`.split.map &:to_i
p=0;q=r
puts a.all?{|e|(e<l+q||(p=l+[p+l,r].max)<q=e)&&r=e}?:YES: :NO
