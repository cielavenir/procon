#!/usr/bin/ruby
a,ta,b,tb,h,m=$<.read.tr(':',' ').split.map(&:to_i)
x1=h*60+m;y1=x1+ta
r=0
300.step(1440-1,b){|x2|
	y2=x2+tb
	r+=1 if [x1,x2].max < [y1,y2].min
}
p r