#!/usr/bin/ruby
class Array
	def mirrorLR() return self.map{|e|e.reverse} end
	def mirrorUD() return self.transpose.map{|e|e.reverse}.transpose end
end
h={'R'=>[1,0],'L'=>[-1,0],'U'=>[0,-1],'D'=>[0,1],'RU'=>[1,-1],'RD'=>[1,1],'LU'=>[-1,-1],'LD'=>[-1,1]}
a=gets.split;x=a[0].to_i+7;y=a[1].to_i+7;w=a[2]
m=Array.new(9).map{|e|Array.new}
m[4]=9.times.map{gets.chomp.split('')}
m[0]=m[2]=m[6]=m[8]=m[4].mirrorLR.mirrorUD
m[3]=m[5]=m[4].mirrorLR
m[1]=m[7]=m[4].mirrorUD
z=Array.new(27).map{|e|Array.new}
27.times{|i|27.times{|j|z[j]<<m[j/9*3+i/9][j%9][i%9]}}
z.delete_at(17);z.delete_at(8)
z=z.transpose;z.delete_at(17);z.delete_at(8);z=z.transpose
s="";4.times{|i|s+=z[y+h[w][1]*i][x+h[w][0]*i]};puts s