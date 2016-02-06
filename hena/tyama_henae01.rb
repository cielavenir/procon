#!/usr/bin/ruby
#http://qiita.com/Nabetani/items/4bf43031749c81c35526
#http://nabetani.sakura.ne.jp/hena/orde01rotbk/

STDOUT.sync=true
while gets
	a=$_.chomp.split(':')
	n=a[0].to_i
	a=a[1][1..-2].split(')(').map{|e|e.split(',').map(&:to_i)}

	width=a[0].reduce(:+)
	m=width.times.map{[nil]*width}
	aheight=[0]*width # 各列何行目まで埋めたか
	mheight=0 # aheightの最小値
	a.each{|e|
		cur=0
		x=0
		width.times{|i|
			if aheight[i]==mheight
				break if cur==e.size ### 同じ行だが別のグループ ###
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
	m=m.reverse.transpose

	lst={}
	m.each{|line|
		# その行で始まるグループ一覧 (lineに2つ以上グループが存在することがある)
		a=line.uniq.chunk{|e|!lst.include?(e)}.select{|k,v|k}.map{|k,v|v}
		a.each{|e|
			e.each{|f|lst[f]=1}
			n-=1
			if n==0
				puts '('+e*','+')'
				break
			end
		}
	}
end