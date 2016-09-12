#!/usr/bin/ruby
n,*a=$<.map &:to_i;a.sort!;r=0;n.times{|i|r=(r+a[i]*a[-i-1])%10007};p r