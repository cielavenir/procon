#!/usr/bin/ruby
if true
#prepare coreutils factor (with gmp support)
FACTOR='gfactor'
N=280671392065546467397265294532969672241810318954163887187279320454220348884327
io=open(%Q(| "#{FACTOR}" #{N}))
table=io.gets.split[1..-1].map(&:to_i)
else
table=[162425297,215940091,358456949,369941863,369941863,479871607,706170617,481362815814826159]
end
l=table.size
m=N*2+1
r=nil
(3**l).times{|i|
	table2=Array.new(3){|a|a=[]}
	table.each_with_index{|e,j|table2[i/3**j%3]<<e}
	edge=table2.map{|e|e.reduce(:*)||1}
	surface=edge[0]*edge[1]+edge[1]*edge[2]+edge[2]*edge[0]
	if surface<m
		m=surface
		r=table2
	end
}
=begin
i=0
table.permutation{|a|
	idx=l.times.find_all{|i|a[i]=='|'}
	table2=[a[0...idx[0]],a[idx[0]+1...idx[1]],a[idx[1]+1...l]]
	edge=table2.map{|e|e.reduce(:*)||1}
	surface=edge[0]*edge[1]+edge[1]*edge[2]+edge[2]*edge[0]
	if surface<m
		m=surface
		r=table2
	end
	i+=1
	p i
}
=end
#p r #[[162425297, 481362815814826159], [215940091, 369941863, 706170617], [358456949, 369941863, 479871607]]
puts r.map{|e|e.reduce(:*)||1}.sort*'x'
__END__
56412637156759097412131861x63634925160141537479761109x78185498323479435878944223

まず、coreutilsの"factor 280671392065546467397265294532969672241810318954163887187279320454220348884327"を用いて素因数分解を行った。
(factorはgmpが有効なもの)
得られた素因数は8個と少なかったので、それらと仕切り2つ、合計10個の順列を取り、総当りで表面積(の半分)の最小値を求めた。
訂正:10!よりも3**8の方が明らかに計算量が少ない。