#!/usr/bin/ruby
x,y,X,Y=gets.split.map &:to_i;x-=X;y-=Y;puts ([y<0??N:?S]*y.abs+[nil]*99).zip([x<0??W:?E]*x.abs).map(&:join)