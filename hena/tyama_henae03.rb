#!/usr/bin/ruby
#http://qiita.com/Nabetani/items/b8bf742d278c6cf501aa
#http://nabetani.sakura.ne.jp/hena/orde03nofconv/

D=[0,1,1,0,0,1,1,0,0,1]
Vertex=D.each.with_index(1).map{|e,r|
	20.times.map{|i|Complex(r*Math.cos(-(2*i+e)*Math::PI/20),r*Math.sin(-(2*i+e)*Math::PI/20))}
}
def mapping(s)
	if s=='00'
		(20.times.flat_map{|i|[[0,i],[1,i]]}+[[0,0]]).each_cons(2).map(&:reverse)
	else
		n,m=s[0].to_i-1,s[1].ord-97
		f=n%2
		[
			[n*2,(m+n/2)%20],
			[n*2+1,(m+n/2+f)%20],
			[n*2+2,(m+n/2+f)%20],
			[n*2+3,(m+n/2)%20],
			[n*2+2,(m+n/2-(f^1))%20],
			[n*2+1,(m+n/2-(f^1))%20],
			[n*2,(m+n/2)%20]
		].each_cons(2).to_a
	end
end

STDOUT.sync=true
while gets
	data=$_.chomp.scan(/../)
	if false #どちらでも通ります
		h=Hash.new(0)
		edges=data.flat_map{|e|mapping(e)}
		edges.map(&:sort).each{|e|e.each{|f|h[f]+=1}}
		r=h.select{|k,v|v==2}.map(&:first)
		if data.include?('00')
			r.reject!{|x,y|x==0}
		end
		p r.size
	else
		h=Hash.new{|h,k|h[k]=[]}
		data.flat_map{|e|mapping(e)}.each{|e|h[e.sort]<<e}
		edges=h.select{|k,v|v.size==1}.flat_map(&:last)
		r=0
		while !edges.empty?
			cycle=[edges.shift]
			while cycle.last[1]!=cycle.first[0]
				edges.size.times{|i|
					if edges[i][0]==cycle.last[1]
						cycle<<edges[i]
						edges.delete_at(i)
						break
					end
				}
			end
			cycle=cycle.map{|e|e.map{|n,m|Vertex[n][m]}}.map{|e,f|
				f-e
			}
			r+=cycle.size.times.count{|i|
				# 外積を手早く計算したくてComplexにした
				(cycle[i].conj*cycle[(i+1)%cycle.size]).imag>0
			}
		end
		p r
	end
end

__END__
## 前提
- まず、枠ごとに辺を割り振る(mapping)。このとき、反時計回りに繋がるように注意する。
- 1aは`[[0,0],[1,0],[2,0],[3,0],[2,19],[1,19],[0,0]].each_cons(2).to_a`となる。

## 最初の方針
- 重複している辺を取り除く。
- 残った辺について閉路を検出する。辺自体が反時計回りという情報を持っているので、辺の集合の前側(edges[i][0])だけ見れば良い。
- それぞれの閉路について、x,y座標を算出し、ベクトルに変換、隣接したベクトルの外積を計算する。外積が正なら180°未満の頂点である。
  - 鈍角・鋭角ではなく凸か凹かなので内積ではなく外積。
- ドーナツ型の場合、内側の閉路が検出されることがある。しかし、 **この閉路は時計回りになっている。** したがって、外積の符号は逆になる。外積が正の個数を数えればよいのは変わらないのである。

## 新しい方針
- しかし、これだけのものを60分でその場で実装できるはずはない。あくまで帰宅後の清書である。
- ロスタイム中に、 **頂点数が1個ならば採用すべき頂点である** ことがわかった。言い換えれば、伸びている辺が2本、である。
- ただし、00が含まれる場合は一番内側の頂点を除けば良い。