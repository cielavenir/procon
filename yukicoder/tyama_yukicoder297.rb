#!/usr/bin/ruby
gets
D=[]
O=[]
gets.split.sort.each{|e|D<<Integer(e).to_s rescue O<<e}
n=D.size-O.size
L=D[-n..-1].reverse*''
M=D[0...-n]
E=D.each_slice(O.size+1).to_a
print eval(L+O.zip(M.reverse).map{|x,y|x+y}*''),' ',(O-[?+]==[]?E.shift.zip(*E).reduce(0){|s,e|s+e.join.to_i}:eval(M.zip(O).map{|x,y|x+y}*''+L))