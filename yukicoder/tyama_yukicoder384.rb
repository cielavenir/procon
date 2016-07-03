#!/usr/bin/ruby
h,w,n,k=gets.split.map &:to_i;puts (h+w-2)%n+1==k ?:YES: :NO