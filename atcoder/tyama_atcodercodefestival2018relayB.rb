#!/usr/bin/ruby
T={'L'=>[-1,0],'R'=>[1,0],'U'=>[0,-1],'D'=>[0,1]}
s=gets.chomp
gx,gy=gets.split.map &:to_i
(puts :Yes;exit)if gx==0&&gy==0
%w(L R U D).permutation{|e|x=y=0;s.tr('WXYZ',e*'').chars{|c|x+=T[c][0];y+=T[c][1];(puts :Yes;exit)if x==gx&&y==gy}}
puts :No
