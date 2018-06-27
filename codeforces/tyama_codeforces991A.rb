#!/usr/bin/ruby
a,b,c,n=gets.split.map &:to_i;x=n-a-b+c;p a<c||b<c||x<1?-1:x
