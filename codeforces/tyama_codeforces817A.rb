#!/usr/bin/ruby
X,Y,x,y,a,b=$<.read.split.map &:to_i
x-=X
y-=Y
puts x%a==0&&y%b==0&&x/a%2==y/b%2 ? :YES : :NO
