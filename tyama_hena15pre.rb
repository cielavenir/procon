#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/0b56395d4c9e7c64b230
#http://nabetani.sakura.ne.jp/hena/ord15subpalin/
def local_alignment(x, y)
	#initialize
	a = Array.new(x.size+1){Array.new(y.size+1, 0)}
	back = Array.new(x.size+1){Array.new(y.size+1, 0)}
	tx = ""; ty = ""; t=""

	#DP
	1.step(a.size-1){|i| a[i][0] = a[i-1][0] - 0;back[i][0]=[i-1,0,  "a"]}
	1.step(a[0].size-1){|j| a[0][j] = a[0][j-1] - 0;back[0][j]=[0,  j-1,"b"]}
	1.step(a.size-1){|i|
		1.step(a[0].size-1){|j|
			z = [a[i-1][j-1] + (x[i-1,1]==y[j-1,1] ? 1 : 0), a[i-1][j], a[i][j-1]].each_with_index.to_a.max
			a[i][j]=z[0];
			if a[i][j]>0
				case z[1]
					when 0 then back[i][j]=[i-1,j-1,"c"]
					when 1 then back[i][j]=[i-1,j,  "a"]
					when 2 then back[i][j]=[i,  j-1,"b"]
				end
			else
				a[i][j]=0
			end
		}
	}

	#trace-back
	n=0;m=0;max=0
	(x.size+1).times{|i|
		(y.size+1).times{|j|
			if a[i][j]>max
				max=a[i][j]
				n=i
				m=j
			end
		}
	}
	return max
=begin
	_n=n
	_m=m

	while a[n][m]>0 do
		t+=back[n][m][2]
		n,m = back[n][m][0],back[n][m][1]
	end
	t.reverse!

	#output
	i=n;j=m
	t.chars{|c|
		case c
			when "c" then tx+=x[i].chr; i+=1; ty+=y[j].chr; j+=1;
			when "a" then tx+=x[i].chr; i+=1; ty+="";
			when "b" then tx+="";            ty+=y[j].chr; j+=1;
		end
	}

	p a[_n][_m]
	puts tx
	puts ty
=end
end

STDOUT.sync=true
while gets
	l=$_.chomp
	p [
		(l.size-1).times.map{|i|local_alignment(l[0,i].reverse,l[i+1..-1])*2+1}.max||1,
		(l.size).times.map{|i|local_alignment(l[0,i].reverse,l[i..-1])*2}.max,
	].max
end