#!/usr/bin/ruby
class Array
  def sum
    ret=0
    self.size.times{|i| ret+=self[i]}
    return ret
  end
end

a=Array.new(8)
8.times{|i|
  a[i]=gets.chomp.unpack("C*").map!{|i|i-=87}
}
m=M=0
8.times{|i|
  if a[i].sum==-168 then m+=1 end
}
if m==8 then puts 8; exit end
8.times{|i|
  if a.transpose[i].sum==-168 then M+=1 end
}
puts m+M