#!/usr/bin/ruby
s=gets.chomp
t={'R'=>0,'B'=>1,'Y'=>2,'G'=>3}
h=[]
r=[0]*4
s.each_char.with_index{|c,i|
	h[i%4]=c if c!='!'
}
s.each_char.with_index{|c,i|
	r[t[h[i%4]]]+=1 if c=='!'
}
puts r*' '
