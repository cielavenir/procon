#!/usr/bin/ruby
n,k=gets.split.map &:to_i;n,k=n>k ?[n+k-1,n-1]:[n,k%n];p [*1..n].combination(k).size%(10**9+7)
