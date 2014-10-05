#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/8a973a47633558f54ba8
#http://nabetani.sakura.ne.jp/hena/ord26tribo/

#赤線=[0,1]
#緑線=[1,0]
#青線=[-1,1]
A=('a'..'y').map{|e|
	t_col=e.ord-'a'.ord+1
	row=1
	row_cells=1
	while t_col>row_cells
		t_col-=row_cells
		row+=1
		row_cells=row*2-1
	end
	row=row #-1
	col=t_col-1
	f=col%2
	col/=2
	#終点の座標
	f==0 ?
		[[row-col-1,col+1],[row-col,col],[row-col-1,col+1]] :
		[[row-col-1,col+1],[row-(col+1),col+1],[(row-1)-col-1,col+1]]
}

if $0==__FILE__
	STDOUT.sync=true
	while gets
		idxes=$_.chomp.split('').map{|e|e.ord-'a'.ord}
		puts A.each_with_index.select{|e,i|idxes.include?(i)}.map(&:first).transpose.map{|e|
			h=Hash.new(0)
			e.each{|f|h[f]+=1}
			h.count{|k,v|v==1}
		}*','
	end
end