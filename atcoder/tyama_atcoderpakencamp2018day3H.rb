#!/usr/bin/ruby
n=gets.to_i;r=[k=0];(r<<[n%5,*[5]*k]*?*;k+=1;n/=5)while n>0;$><<r*?+
