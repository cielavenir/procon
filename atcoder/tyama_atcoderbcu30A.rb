#!/usr/bin/ruby
n,_,*a=`dd`.split.map &:to_i
x=0
a.map{|e|(n==x+=e)&&break;x>n&&x-=x-n<<1}
p x
