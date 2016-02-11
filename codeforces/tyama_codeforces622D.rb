#!/usr/bin/ruby
n=gets.to_i;puts ((1+n%2).step(n-1,2).to_a+(n-1).step(1,-2).to_a+(2-n%2).step(n,2).to_a+(n-2).step(1,-2).to_a+[n])*' '