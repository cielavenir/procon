#!/usr/bin/ruby
H,W=gets.split.map &:to_i
M=$<.to_a
a=[]
H.times{|h|W.times{|w|M[h][w]==?*&&a<<[h,w]}}
if a[0][0]!=a[1][0]&&a[0][1]!=a[1][1]
	h,w=a[0][0],a[1][1]
else
	h,w=[[0,0],[H-1,0],[0,W-1]].find{|e|a.transpose.zip(e).none?{|x,y|x.count(y)>1}}
end
M[h][w]=?*
puts M
__END__
星が斜めに配されている時、片方の座標だけを入れ替える
そうでないとき、四隅の中で、「x座標y座標のいずれも星一覧に2回含まれない」ものを選ぶ(ただし実際には右下は必要ない)
