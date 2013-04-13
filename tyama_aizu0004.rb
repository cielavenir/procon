#!/usr/bin/ruby
while gets
a,b,c,d,e,f=$_.split.map(&:to_f)
x=a*e-b*d
printf"%.3f %.3f\n",(e*c-b*f)/x,(a*f-d*c)/x
end