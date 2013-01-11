#!/usr/bin/ruby
n=gets.chomp.to_i
h=Hash.new;h.default=0
a=Array.new
n.times{|z|
  s=gets.chomp.split(" ")
  s[1]=s[1].to_i
  h[s[0]]+=s[1]
  a.push(s)
}
m=h.values.max
h.each_key{|k| h[k]=(h[k]==m)?0:nil}

#re-read
a.each{|i|
  if h[i[0]]
    h[i[0]]+=i[1]
    if h[i[0]]>=m then puts i[0]; exit end
  end
}