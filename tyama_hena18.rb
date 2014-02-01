#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/ad47666c2f2f44ada1e7
#http://nabetani.sakura.ne.jp/hena/ord18notfork/
A=[2,7,3,5,2]
while gets
	a=[0]*A.size
	bug=[nil]*A.size
	$_.each_char{|c|
		if c=='.'
			A.size.times{|i|
				if bug[i]
					num=[A[i],bug[i]].min
					a[i]-=num
					bug[i]-=num
				else
					a[i]-=A[i]
					a[i]=0 if a[i]<0
				end
			}
		else
			n=a.each_with_index.min.last
			if c=='x'
				bug[n]=a[n] if !bug[n]
				a[n]+=1
			else
				a[n]+=c.to_i
			end
		end
	}
	puts a*','
end