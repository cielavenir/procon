#!/usr/bin/ruby
n=gets.to_i
h=Hash.new
n.times{|i|
  x=s=gets.chomp
  if !h[s]
    h[s]=0
    puts "OK"
  else
    h[s]+=1
    puts s+h[s].to_s
  end
}