#!/usr/bin/ruby
z=k=0
1.upto(n=gets.to_i){|i|z+=(-k+k=i**10)*(n/i)**10}
p z%(10**9+7)
