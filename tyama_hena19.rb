#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/9810b301648099028bf0
#http://nabetani.sakura.ne.jp/hena/ord19nebasec/
def connect(h,a,b)
	h[a]<<b
	h[b]<<a
end
$h=Hash.new{|h,k|h[k]=[]}
32.times{|i|
	d=i/4
	r=i%4
	if r==0
		connect($h,400+d*4+r,300+d*3)
	elsif r==1
		connect($h,400+d*4+r,300+d*3)
		connect($h,400+d*4+r,300+d*3+1)
	elsif r==2
		connect($h,400+d*4+r,300+d*3+1)
		connect($h,400+d*4+r,300+d*3+2)
	elsif r==3
		connect($h,400+d*4+r,300+d*3+2)
		connect($h,400+d*4+r,300+(d*3+3)%24)
	end
	connect($h,400+i,400+(i+1)%32)
}
24.times{|i|
	d=i/3
	r=i%3
	if r==0
		connect($h,300+d*3+r,200+d*2)
	elsif r==1
		connect($h,300+d*3+r,200+d*2)
		connect($h,300+d*3+r,200+d*2+1)
	elsif r==2
		connect($h,300+d*3+r,200+d*2+1)
		connect($h,300+d*3+r,200+(d*2+2)%16)
	end
	connect($h,300+i,300+(i+1)%24)
}
16.times{|i|
	d=i/2
	r=i%2
	if r==0
		connect($h,200+d*2+r,100+d*1)
	elsif r==1
		connect($h,200+d*2+r,100+d*1)
		connect($h,200+d*2+r,100+(d*1+1)%8)
	end
	connect($h,200+i,200+(i+1)%16)
}
8.times{|i|
	connect($h,100+i,100+(i+1)%8)
}

STDOUT.sync=true
while gets
	h=Hash.new(0)
	a=$_.split(',').map(&:to_i)
	a.each{|e|$h[e].each{|f|h[f]+=1}}
	r=h.select{|k,v|v>=2}.map(&:first).sort-a
	puts r.size>0 ? r*',' : 'none'
end