#!/usr/bin/ruby
A=[[0,0,0],[0,0,255],[0,255,0],[0,255,255],[255,0,0],[255,0,255],[255,255,0],[255,255,255]]
B=['black','blue','lime','aqua','red','fuchsia','yellow','white']
while(l=gets)!="0\n"
puts A.length.times.map{|i|[A[i].zip(l[1..-1].unpack("a2a2a2").map{|e|e.to_i(16)}).map{|e|(e[0]-e[1])**2}.reduce(:+),B[i]]}.min[1]end