#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/9c514267214d3917edf2
#STDOUT.sync=true
$dx=[-2,2,0,0];$dy=[0,0,-2,2]
M=Array.new(9){Array.new(9)}
def d(x,y,d)
	if x==8&&y==8
		$r+=1
	else
		4.times{|i|
			if 0<=x+$dx[i]&&x+$dx[i]<=8 && 0<=y+$dy[i]&&y+$dy[i]<=8
				if !M[y+$dy[i]][x+$dx[i]]&&!M[y+$dy[i]/2][x+$dx[i]/2]
					M[y+$dy[i]][x+$dx[i]]=1
					d(x+$dx[i],y+$dy[i],d+1)
					M[y+$dy[i]][x+$dx[i]]=nil
				end
			end
		}
	end
end
DATA.each_with_index{|e,i|
	$r=0
	M.map!{Array.new(9)}
	M[0][0]=1
	input,expect=e.chomp.split(' -> ')
	expect=expect.to_i
	input[1...-1].split(' ').each{|e|
		a=e.chars.map{|e|e.ord-97}
		d=a[1]-a[0]
		raise if d!=1&&d!=5
		x=a[0]%5*2
		y=a[0]/5*2
		M[y+d/5][x+d%5]=1
	}
	d(0,0,0)
	#p $r
	puts 'Case '+(i+1).to_s+': '+(expect==$r?'OK':'NG')
}
__END__
"" -> 8512 #そのまま。これが最大値。
"af" -> 4256 #対称性より半分になる
"xy" -> 4256 #対称性より半分になる
"pq qr rs st di in ns sx" -> 184 #3x3マスと同値
"af pq qr rs st di in ns sx" -> 92 #3x3マスのパターンの半分
"bg ch di ij no st" -> 185 #3x3マスのパターン +1
"bc af ch di no kp mr ns ot pu rs" -> 16 #4x2x2
"ab af" -> 0 #入口を塞いだ
"ty xy" -> 0 #出口を塞いだ
"bg ch ej gh lm lq mr ot rs sx" -> 11 #2x4+3
"ty ch hi mn kp mr rs sx" -> 18 #6*3
"xy ch hi mn kp mr rs sx" -> 32 #4*8
"ch hi mn kp mr rs sx" -> 50 #6*3+4*8
"ab cd uv wx" -> 621 
"gh mn st lq qr" -> 685 
"fg gl lm mr rs" -> 171