#!/usr/bin/env ruby
#http://mtsmfm.github.io/2016/10/01/doukaku-e08.html
#http://qiita.com/mtsmfm/items/94ebd353fa3b7e608f68

H=W=19
while gets
	# 要素が0..18の数値2つ(x座標,y座標)からなる配列
	a=$_.chomp.split(',').map{|e|e.scan(/[a-z]\d+/).map{|f|[f[0].ord-97,f[1..-1].to_i-1]}.sort}
	h=a.map{|e|Hash[*e.flat_map{|(x,y)|[x+y*W,1]}]}
	puts 2.times.map{|i|
		#相手のフィールド：駒を配置して累積和を取る
		#cf: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0098
		opponent=(H+1).times.map{[0]*(W+1)}
		a[i^1].each{|x,y|opponent[y+1][x+1]=1}
		(H+1).times.map{|y|W.times.map{|x|opponent[y][x+1]+=opponent[y][x]}}
		H.times.map{|y|(W+1).times.map{|x|opponent[y+1][x]+=opponent[y][x]}}

if false
		#自分の駒を列挙するには方法が2つある
		#1:3点を列挙して、矩形をなすもう1点の存在を判定する
		#2:x座標の2つ組とy座標の2つ組をそれぞれ列挙して、4点の存在を判定する
		#今回は、列挙する個数が少ない方を自動で選択するようにした
		#(テストケースに依存するが、今回は0.6sから0.5sに高速化)
		xl,yl=a[i].transpose.map{|e|e.uniq.sort}
		f = if a[i].size*(a[i].size+1)*(a[i].size+2)/6 < xl.size*(xl.size+1)*yl.size*(yl.size+1)/4
			Enumerator.new{|y|
				a[i].combination(3){|b|
					if b[0][0]==b[1][0] && b[0][1]==b[2][1] && h[i][b[2][0]+b[1][1]*W]
						y<<[b[1][0],b[2][0]+1,b[2][1],b[1][1]+1]
					end
				}
			}
		else
			Enumerator.new{|y|
				xl.combination(2).to_a.product(yl.combination(2).to_a).each{|(w1,w2),(h1,h2)|
					if h[i][w1+h1*W] && h[i][w1+h2*W] && h[i][w2+h1*W] && h[i][w2+h2*W]
						y<<[w1,w2+1,h1,h2+1]
					end
				}
			}
		end
else
		#cia_ranaさんのアルゴリズムを再現してみました
		#https://bitbucket.org/snippets/cia_rana/aoqqq/e08
		f = Enumerator.new{|z|
			st=0
			a[i].chunk{|x,y|x}.each{|k,v|
				st+=v.size
				(v.size-1).times{|j|
					same_y=a[i][st..-1].select{|x0,y0|y0==v[j][1]}
					(j+1...v.size).each{|k|
						if q=same_y.find{|x0,y0|h[i][x0+v[k][1]*W]}
							z<<[v[j][0],q[0]+1,v[j][1],v[k][1]+1]
						end
					}
				}
			}
		}
end

		#4点が存在することを確認したら、最後に、内部に相手の駒がないことを確認し、陣地に加える
		#陣地の管理はいもす法( http://imoz.jp/algorithms/imos_method.html )を用いる
		#cf: http://qiita.com/cielavenir/items/f5c3fcc0553ce0751b29 (paiza poh5 4b)
		imos=(H+1).times.map{[0]*(W+1)}
		f.each{|w1,w2,h1,h2|
			if opponent[h1][w1]-opponent[h1][w2]-opponent[h2][w1]+opponent[h2][w2]==0
				imos[h1+1][w1+1]+=1
				imos[h1+1][w2]-=1
				imos[h2][w1+1]-=1
				imos[h2][w2]+=1
			end
		}
		(H+1).times.map{|y|W.times.map{|x|imos[y][x+1]+=imos[y][x]}}
		H.times.map{|y|(W+1).times.map{|x|imos[y+1][x]+=imos[y][x]}}
		r=0
		(H+1).times.map{|y|(W+1).times.map{|x|r+=1 if imos[y][x]>0}}
		r
	}*','
	STDOUT.flush
end
