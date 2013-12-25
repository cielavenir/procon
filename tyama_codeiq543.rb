#!/usr/bin/ruby
from=Time.gm(1964,10,10)
to=t=Time.gm(2020,7,24)
a=[]
while from<=to
	day=from.strftime('%Y%m%d')
	a<<day if day.to_i.to_s(2)==day.to_i.to_s(2).reverse
	from+=86400
end
puts a*',' # 19660713,19660905,19770217,19950617,20020505,20130201