#!/usr/bin/ruby
M=1000000007;gets;a=$<.map &:to_i;m=a.min;n=m+(a.map{|e|e-m}.reduce(&:gcd)+e=1)/r=2;while n>0;n%2>0&&e=r*e%M;r=r*r%M;n/=2 end;p e