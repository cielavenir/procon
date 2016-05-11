#!/usr/bin/ruby
n,k,*a=$<.read.split.map(&:to_i)<<r=0;n.times{|i|a[i]+=a[i-1];i>k-2&&r+=a[i]-a[i-k]};p r