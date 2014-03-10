#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/9810b301648099028bf0
#http://nabetani.sakura.ne.jp/hena/ord19nebasec/
$h=Hash.new{|h,k|h[k]=[]}
1.step(4){|m|
	(8*m).times{|i|
		edges=[]
		if m>1
			d=i/m
			r=i%m
			if r==0
				edges<<(m-1)*100+d*(m-1)
			else
				edges<<(m-1)*100+(d*(m-1)+r-1)%(8*(m-1))
				edges<<(m-1)*100+(d*(m-1)+r-0)%(8*(m-1))
			end
		end
		edges<<m*100+(i+1)%(8*m)
		edges.each{|e|
			$h[m*100+i]<<e
			$h[e]<<m*100+i
		}
	}
}

STDOUT.sync=true
while gets
	h=Hash.new(0)
	a=$_.split(',').map(&:to_i)
	a.each{|e|$h[e].each{|f|h[f]+=1}}
	r=h.select{|k,v|v>=2}.map(&:first).sort-a
	puts r.size>0 ? r*',' : 'none'
end