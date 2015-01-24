#!/usr/bin/ruby
#s=0;gets.scan(/((25)+)/){|e|s+=(n=e[0].size)*(n+2)/8};p s
s=0;gets.scan(/((25)+)/){|e|s+=(e[0].size+1)**2/8};p s