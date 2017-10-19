#!/usr/bin/ruby
n,*a=$<.map &:to_i;p a[0,2].min*(2--~n/n)+a.min*[0,n-2].max
