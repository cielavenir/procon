#!/usr/bin/ruby
A=[]
l,s,t=$<.map &:chomp
l=l.to_i
a=s.size
b=t.size
2.times{
x=y=0
y+=b while (l-y)%a>0
x=l-y
A<<s*(x/a)+t*(y/b)<<t*(y/b)+s*(x/a)
s,t,a,b=t,s,b,a
}
puts A.min
