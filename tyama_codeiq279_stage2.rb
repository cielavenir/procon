#!/usr/bin/ruby
#NEWICK=true
NEWICK=false

CODES=['r','g','b']
WIDTH=CODES.size
def dfs(str,code) #assign code
	r=[]
	c=i=0
	while str[i,1]!=')'
		if str[i,1]=='('
			r+=dfs(str[i+1..-1],code+CODES[c])
			x=1
			while x>0
				x+=1 if str[i+1,1]=='('
				x-=1 if str[i+1,1]==')'
				i+=1
			end
		else
			r+=[str[i,1]+':'+code+CODES[c]]
		end
		c+=1
		i+=1
	end
	return r
end
h={}
DATA.each{|e|
	s,n=e.split
	h[s]=n.to_i
}
#build huffman tree
a=h.map{|k,v|[v,k]}.sort
if (h.size-WIDTH)%(WIDTH-1)>0
	b=a.shift(WIDTH-(h.size-WIDTH)%(WIDTH-1)).transpose
	a=(a+[[b[0].reduce(:+),'('+b[1]*(NEWICK ? ',' : '')+')']]).sort
end
while a.size>1
	b=a.shift(WIDTH).transpose
	raise if b[0].size!=WIDTH
	a=(a+[[b[0].reduce(:+),'('+b[1]*(NEWICK ? ',' : '')+')']]).sort
end
# a => [[9371, "((O(((Q(XZ)J)VB)YW)I)(AT(U(PFK)L))(E(DRS)(N(GMC)H)))"]]
if NEWICK
	# ((O,(((Q,(X,Z),J),V,B),Y,W),I),(A,T,(U,(P,F,K),L)),(E,(D,R,S),(N,(G,M,C),H)));
	puts a[0][1]+';'
	exit
end
r=dfs(a[0][1][1..-1],'')
#r.sort_by{|e|e.split(':')[1].size}.each{|e|
r.sort.each{|e|
	puts e
}

=begin
A:gr
B:rgrb
C:bbgb
D:bgr
E:br
F:gbgg
G:bbgr
H:bbb
I:rb
J:rgrrb
K:gbgb
L:gbb
M:bbgg
N:bbr
O:rr
P:gbgr
Q:rgrrr
R:bgg
S:bgb
T:gg
U:gbr
V:rgrg
W:rgb
X:rgrrgr
Y:rgg
Z:rgrrgg

この問題はA-Zをrgbの3種類の文字で符号化した時に文字数が最小となるように、rgbを割り当てる問題である。なのでまず最初に、コード[1]を用いて出現頻度表を作成した。
次にコード[2]を用いて
http://ja.wikipedia.org/wiki/%E3%83%8F%E3%83%95%E3%83%9E%E3%83%B3%E7%AC%A6%E5%8F%B7#.E7.AC.A6.E5.8F.B7.E5.8C.96.E3.81.AE.E5.8E.9F.E7.90.86
に従ってハフマン木を作成し、それに符号rgbを割り当てた。
この例は2分木だが、「より小さい値を持つ3つの接点を取り出す」と読み替えることで3分木に応用出来る。
ところで、3分木は、葉の数が2n+3でなければ完全な3分木にはならない。今回の葉の数は26なので当てはまらない(1個不足している)。
この方法で作成するハフマン木に割り当てられる符号が最小となるためには、一番下以外は必ず3つの子を持つ必要がある。よって最小の2つで接点を作る必要がある。

コード[3]でチェックしたところ、「文字リンゴ対応表 Version 1」は28113(3-bits)、「文字リンゴ対応表 Version 2」は24971(3-bits)であった。
=end
__END__
E 1194
T 1001
A 805
I 694
O 662
H 653
N 581
S 572
R 460
D 410
L 398
U 295
W 246
Y 226
C 209
M 201
G 199
K 123
F 121
P 110
B 107
V 74
J 11
Q 9
Z 5
X 5