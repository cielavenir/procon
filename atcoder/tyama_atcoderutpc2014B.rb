#!/usr/bin/ruby
def output(x0,y0,x1,y1)
	x0=(x0+$diffx)*$sgnx
	y0=(y0+$diffy)*$sgny
	x1=(x1+$diffx)*$sgnx
	y1=(y1+$diffy)*$sgny
	puts [x0,y0,x1,y1]*' '
end

x,y=gets.split.map{|e|e.tr('.','').to_i}
$sgnx=1
$sgny=1
if x<0
	$sgnx=-1
	x=-x
end
if y<0
	$sgny=-1
	y=-y
end
$diffx=x/1000
x=x%1000
$diffy=y/1000
y=y%1000

if x==y
	output(0,x,1,-1000+2*x)
else
	output(1,1,1001-x,1001-y)
end

if x==0 && y==0
	output(0,0,1,0)
else
	output(0,0,x,y)
end