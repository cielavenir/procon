#!/usr/bin/ruby
gets
e=gets.split.map &:to_i
d=[0,-1,0,1]
c=[]
while d.size<=e.size
c<<x=e[-1]/d[-1]
d.size.times{|i|e[i+e.size-d.size]-=d[i]*x}
e.pop
end
e.pop while e.size>1&&e[-1]==0
p e.size-1
puts e*' '