#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/4c60f10b73812e86441c
#http://nabetani.sakura.ne.jp/hena/ord6lintersection/
STDOUT.sync=true
def z(a,b)
	([a[0],b[0]].min..[a[0],b[0]].max).map{|f|
		([a[1],b[1]].min..[a[1],b[1]].max).map{|g|f*10+g}
	}.flatten
end
while gets
	p $_.split(',').map{|e|
		a,b,c=e.split('-').map{|f|f.split('').map(&:to_i)}
		z(a,b)|z(a,c)
	}.reduce(&:&).size
end