#!/usr/bin/ruby
T={'purple'=>'Power','green'=>'Time','blue'=>'Space','orange'=>'Soul','red'=>'Reality','yellow'=>'Mind'}
A=[];gets;$<.each{|e|A<<T[e.chomp]};B=T.values-A;p B.size;puts B
