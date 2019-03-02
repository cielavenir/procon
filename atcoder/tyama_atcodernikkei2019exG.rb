#!/usr/bin/ruby
h=Hash.new 0
gets.chomp.chars{|c|h[c]+=1}
x=y=0
h.each_value{|v|d,r=v.divmod 2;x+=d*2;y+=r}
y>0&&(y-=1;x+=1)
p x**2+y
