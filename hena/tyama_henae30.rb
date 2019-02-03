#!/usr/bin/ruby
#http://nabetani.sakura.ne.jp/hena/orde30sumt/
#https://qiita.com/Nabetani/items/725e09cc5913a8569c04

while s=gets
	a_,b_=s.chomp.split("/")
	a=a_.split(",").map(&:to_i)
	b=b_.to_i
	width=a[-1]*b*4 ### fixme magic number 4
	#cell id, number
	storage=width.times.map{|i|[i/a[0],i/a[0]+1]}
	(1...a.size).each{|wi|
		interesting={}
		storage.uniq.tap{|z|
			interesting[z[0]]=1
			(1..z.size-2).each{|i|
				interesting[z[i]]=1 if z[i][1]!=z[i-1][1] || z[i][1]!=z[i+1][1]
			}
			interesting[z[-1]]=1
		}
		z0=[]
		w0=a[wi]
		0.step(width-1,w0).with_index{|k,ki|
			su=(k...[k+w0,width].min).select{|i|
				interesting.has_key?(storage[i])
			}.map{|i|
				storage[i]
			}.uniq.map(&:last).reduce(0,:+)%1000
			(k...[k+w0,width].min).each{z0<<[ki,su]}
		}
		storage=z0
	}
	p storage[(b-1)*a[-1]][1]
	STDOUT.flush
end
