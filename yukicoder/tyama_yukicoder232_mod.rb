#!/usr/bin/ruby
T,A,B=gets.split.map &:to_i
puts [A,B].max>T||T+A+B<2?:NO:[:YES]+([?^]*A+[?v,?^]*(T-A>>1)+(z=[[],['']])[T-A&1]).zip(z[T-B&1]+[?>]*B+[?<,?>]*(T-B>>1)).map{|x,y|x+y}