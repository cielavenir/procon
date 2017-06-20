#!/usr/bin/env ruby
#http://nabetani.sakura.ne.jp/hena/ordf05rotblo/
#http://qiita.com/Nabetani/items/a6ed674166a151fd0a0a
STDOUT.sync=true
#def rotate_point_old(a,cx,cy)
#	a.map{|x,y|
#		[-(y*2-cy)+cx,(x*2-cx)+cy].map{|e|e/2}
#	}
#end
def rotate_point(a,cx,cy)
	a.map{|x,y|
		[-(y-cy)+cx,(x-cx)+cy]
	}
end
H=W=5
while gets
	t,a=$_.chomp.split(':')
	b=[]
	H.times{|h|W.times{|w|b<<[w,h] if a[h*(W+1)+w]=='1'}}
	if t=='a'
		b=rotate_point(b,1,2)
	else
		#点群を回転点bの右上のマスからの相対座標とする。
		#右上のマスを右下に移動し、移動後の右下のマスを中心にして回転移動する。
		b=rotate_point(b.map{|x,y|[x,y+1]},2,2)
	end
	#b=rotate_point_old(b,*(t=='a' ? [2,4] : [3,3])) # 左上のマスの中心を原点とする
	if b.any?{|x,y|
		x<0||W<=x || y<0||H<=y
	}
		puts :-
	else
		a=H.times.map{['0']*W}
		b.each{|x,y|a[y][x]='1'}
		puts a.map(&:join)*'/'
	end
end
