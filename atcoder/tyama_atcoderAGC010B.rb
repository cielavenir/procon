#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i
k,z=a.reduce(:+).divmod n*-~n/2
puts z==0&&(0...n).all?{|i|(x=a[(i+1)%n]-a[i]-k)<=0&&x%n==0}?:YES: :NO
