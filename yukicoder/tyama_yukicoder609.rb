#!/usr/bin/ruby
#中央値を使う話,codingameのnetwork cablingとかで既出では.
n,*a=`dd`.split.map &:to_i;x=a.sort[n/2];r=0;a.map{|e|r+=(e-x).abs};p r
