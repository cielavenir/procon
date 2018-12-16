#!/usr/bin/ruby
gets;h=Hash.new r=0
gets.split.map(&:to_i).sort.reverse.map{|e|
	o=1;o*=2 until o>e
	h[e]>0?(h[e]-=1;r+=1):h[o-e]+=1
};p r
