#!/usr/bin/env ruby
#http://qiita.com/items/c206fbc645c255cb7de6
#http://nabetani.sakura.ne.jp/hena/ord11arithseq/
STDOUT.sync=true
while gets
	h={}
	$_.chomp.chars{|e|h[e.to_i(36)]=1} # because already sorted...
	r=1
	0.step(35){|i|
		if h.has_key?(i)
			1.step(35){|j|
				k=1
				while h.has_key?(i+j*k) do k+=1 end
				r=[r,k].max
			}
		end
	}
	p r
end