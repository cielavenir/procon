gets
a=gets.split.map{|i|i=i.to_i}
s=a.inject(0){|s,e|s+e}
t=x=0
(a.size-1).times{|i|x+=s==2*(t+=a[i])?1:0}
p x