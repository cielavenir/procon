#!/usr/bin/ruby
n=gets.to_i
k=i=s=0
s+=(-2+k+=1)*~-k/2+1while s<n
s-=(k-2)*~-k/2+1
(n<=s+k-i-2?(p ('1'*(i+1)+'0'*(s+k-i-n-1)+'1'*(-s+n)).to_i(2);exit):(s+=k-2-i;i+=1))while i<k-2&&s<n
p 2**k-1
