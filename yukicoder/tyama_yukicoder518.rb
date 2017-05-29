#!/usr/bin/ruby
def checkio(data) ['','M','MM','MMM'][data/1000]+['','C','CC','CCC','CD','D','DC','DCC','DCCC','CM'][data/100%10]+['','X','XX','XXX','XL','L','LX','LXX','LXXX','XC'][data/10%10]+['','I','II','III','IV','V','VI','VII','VIII','IX'][data%10] end

def tonum(roman)
    m={'I'=>1,'V'=>5,'X'=>10,'L'=>50,'C'=>100,'D'=>500,'M'=>1000}
    r=0
    roman.size.times{|i|r+=m[roman[i]]*(if i==roman.size-1 or m[roman[i]]>=m[roman[i+1]] then 1 else -1 end)}
    return r
end

gets
n=gets.split.map{|e|tonum(e)}.reduce(:+)
if n>3999
    puts :ERROR
else
    puts checkio(n)
end
