#!/usr/bin/ruby
gets;$<.map{|_|n,a,b,k=_.split.map &:to_i;p (0..n).count{|i|j=n-i;i<=a&&j<=b&&(k==1?i*j==0:n&i==i)}%2}
