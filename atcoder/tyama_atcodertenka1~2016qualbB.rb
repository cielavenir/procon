#!/usr/bin/ruby
s=gets.chomp;(s.size-1).downto(a=b=c=0){|i|s[i]==?)?b>=s.size/2?(a-=1;c+=1;@d||=i):(a+=1;b+=1):a>0?a-=1:(a+=1;b+=1;c+=1;@d||=i)};p c+@d||=0