#!/usr/bin/ruby
require 'prime'
class Integer
    def sopfr()      self.prime_division.reduce(0){|s,(n,p)|s+(n*p)} end
    def factornum()  self.prime_division.reduce(0){|s,(n,p)|s+p} end
    def dfactornum() self.prime_division.reduce(0){|s,(n,p)|s+1} end
    def sopf()       self.prime_division.reduce(0){|s,(n,p)|s+n} end

    def divisornum() self.prime_division.reduce(1){|s,(n,p)|s*(p+1)} end
    def divisorsum() self.prime_division.reduce(1){|s,(n,p)|s*(n**(p+1)-1)/(n-1)} end
    def totient()    self.prime_division.reduce(1){|s,(n,p)|s*(n-1)*n**(p-1)} end

    def derivative() self.prime_division.reduce(0){|s,(n,p)|s+self*p/n} end
end

n=gets.to_i;m=n>>1-n%2;p m;p m.divisorsum
__END__
require'prime';n=gets.to_i;s=1;(n>>1-n%2).prime_division.each{|n,p|s*=(n**(p+1)-1)/~-n};p s
#require'prime';n=gets.to_i;s=1;(n.gcd n*~-n/2).prime_division.each{|n,p|s*=(n**(p+1)-1)/~-n};p s