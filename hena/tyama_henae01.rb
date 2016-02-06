#!/usr/bin/ruby
STDOUT.sync=true
while gets
	a=$_.chomp.split(':')
	n=a[0].to_i
	a=a[1][1..-1].split(')(').map{|e|e.split(',').map(&:to_i)}

	width=a[0].reduce(:+)
	m=width.times.map{[0]*width}
	aheight=[0]*width # 各列何行目まで埋めたか
	mheight=0 # aheightの最小値
	a.each{|e|
		cur=0
		x=0
		width.times{|i|
			if aheight[i]==mheight
				next if cur==e.size # 同じ行だが別のグループ
				e[cur].times{|j|
					m[aheight[i]][i]=e[cur]
					aheight[i]+=1
				}
				x+=1
				if x==e[cur]
					x=0
					cur+=1
				end
			end
		}
		mheight=aheight.min
	}
	#時計回りに回転
	m=m.transpose.map(&:reverse)

	lst={}
	m.each{|line|
		lstprev=lst.dup
		a=[] # その行で始まるグループ一覧
		a0=[]
		line.each{|e|
			if !lst.include?(e)
				a0<<e
				lst[e]=1
			elsif lstprev.include?(e)
				if !a0.empty?
					a<<a0
					a0=[]
				end
			end
		}
		a<<a0 if !a0.empty?
		a.each{|e|
			n-=1
			if n==0
				puts '('+e*','+')'
				break
			end
		}
	}
end