#!/usr/bin/ruby
def fromcell(s)
  r=0
  s.each_byte{|i|
    r=r*26+i-64
  }
  return r
end

def tocell(n)
  r=""
  while n>0
    x=n%26
    if x==0 then x=26; n-=26 end
    r=(x+64).chr+r
    n/=26
  end
  return r
end

n=gets.chomp.to_i
n.times{|z|
  s=gets.chomp
  if s=~/^([A-Z]+)(\d+)$/ then puts "R"+$2.to_s+"C"+fromcell($1).to_s end
  if s=~/R(\d+)C(\d+)/ then puts tocell($2.to_i)+$1.to_s end
}