#!/usr/bin/ruby
n,_=gets.split.map &:to_i
a=gets.split.map(&:to_i).sort
r=0
i=0
p gets.split.map(&:to_i).sort.each{|b|
  while i<n
    break if a[i]>=b
    i+=1
  end
  break if i==n
  r+=a[i]
  i+=1
} ? r : -1
