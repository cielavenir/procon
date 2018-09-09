#!/usr/bin/ruby
s=gets;i,j=gets.split.map &:to_i;s[i],s[j]=s[j],s[i];puts s
