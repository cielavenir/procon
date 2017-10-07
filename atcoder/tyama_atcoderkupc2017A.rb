#!/usr/bin/ruby
n,k,*a=`dd`.split.map &:to_i;a.sort_by! &:-@;s=0;p (1..n).find{|i|k<=s+=a[i-1]}||-1
