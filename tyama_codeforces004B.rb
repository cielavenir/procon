#!/usr/bin/ruby
class Array
  def sum
    ret=0
    self.length.times{|i| ret+=self[i]}
    return ret
  end
end

s=gets.chomp.split(" ").map!{|i|i=i.to_i}
a=Array.new(s[0])
s[0].times{|j|
  a[j]=gets.chomp.split(" ").map!{|i|i=i.to_i}
}
m=a.transpose[0].sum
M=a.transpose[1].sum
if s[1]<m || M<s[1] then puts :NO;exit end

puts :YES
s[1]-=m
s[0].times{|i|
  n=x=a[i][1]-a[i][0]
  if s[1]<x
    n=s[1];s[1]=0
  else s[1]-=x end
  print n+a[i][0]
  print " "
}