#!/usr/bin/ruby
class Integer
  def isqrt
    return 0 if self<=0
    return 1 if self<4 # 1
    x,y=0,self
    while x!=y&&x+1!=y
      x,y=y,(self/y+y)/2
    end
    x
  end
end
n=8*gets.to_i+1
q=n.isqrt
if q**2!=n||q%2==0
  puts :NO
else
  puts :YES
  p q-1>>1
end
