#!/usr/bin/ruby
n=gets.to_i;(1..3500).map{|h|(h..3500).map{|w|z=4*h*w-n*w-n*h;z>0&&(y=n*h*w)%z<1&&(puts [h,w,y/z]*' ';exit)}}
