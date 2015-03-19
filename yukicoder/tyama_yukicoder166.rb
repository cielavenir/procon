#!/usr/bin/ruby
h,w,n,k=gets.split.map &:to_i
puts (h*w-1)%n==k-1?:YES: :NO