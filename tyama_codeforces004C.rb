#!/usr/bin/ruby
h={}
gets.to_i.times{|i|
  x=s=gets.chomp
  if !h[s]
    h[s]=0
    puts :OK
  else
    h[s]+=1
    puts s+h[s].to_s
  end
}