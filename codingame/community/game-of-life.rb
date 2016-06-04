#!/usr/bin/ruby
D=[[-1,-1],[-1,0],[-1,1],[0,-1],[0,1],[1,-1],[1,0],[1,1]]
W,H=gets.split.map(&:to_i)
M=$<.to_a
puts H.times.map{|h|W.times.map{|w|
	x=D.count{|h0,w0|
		0<=h0+h&&h0+h<H && 0<=w0+w&&w0+w<W && M[h0+h][w0+w]=='1'
	}
	((M[h][w]=='1' && [2,3].include?(x)) || (M[h][w]=='0' && 3==x)) ? 1 : 0
}*''}