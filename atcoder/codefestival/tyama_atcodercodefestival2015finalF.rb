#!/usr/bin/ruby
C=gets.split.map(&:to_i)
C[0]-=1
X=[C[0]-C[6]+C[5]-C[4]+C[3]-C[2]+C[1]]
1.upto(6){|i|X[i]=2*C[i]-X[i-1]}
l=0.upto(6).find{|i|X[i]==0}
r=6.downto(0).find{|i|X[i]==0}
puts 7.times.any?{|i|X[i]<0} || (l&&(l..r).any?{|i|X[i]>0}) ? :NO : :YES