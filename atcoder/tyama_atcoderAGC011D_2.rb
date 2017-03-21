#!/usr/bin/ruby
n,k=gets.split.map &:to_i
s=gets.chomp.chars.map &:ord
l=0
((s[l]+l)%2>0&&(s[l]^=3;0==k-=1)&&break;l+=1;k-=1)while k>0&&l<n
s=s.rotate l%n
l%2>0&&s=s.map{|e|e^3}
s[0]^=(n*k)%2*3
$><<s.map(&:chr)*''
