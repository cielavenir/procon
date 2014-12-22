#!/usr/bin/ruby
LON=gets.tr(',','.').to_f*Math::PI/180
LAT=gets.tr(',','.').to_f*Math::PI/180
puts gets.to_i.times.map{
	a=gets.split(';')
	[a[1],a[4].tr(',','.').to_f*Math::PI/180,a[5].tr(',','.').to_f*Math::PI/180]
}.min_by{|_,lon,lat|
	6371*Math.hypot((LON-lon)*Math.cos((LAT+lat)/2),LAT-lat)
}.first