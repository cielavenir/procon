#!/usr/bin/env crystal
gets.not_nil!.to_i.times{
	y,m,d=gets.not_nil!.split.map{|e|e.to_i}
	y-=1;m-=1
	p 196471-y*195-y/3*5-m*20+(y%3!=2?m/2:0)-d
}