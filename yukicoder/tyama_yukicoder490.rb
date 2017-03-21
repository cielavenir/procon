#!/usr/bin/ruby
n,*a=`dd`.split.map(&:to_i)
b=a.sort
b[-1]>a[-1]&&(b[-2,2]=b[-1],b[-2])
puts b*' '
