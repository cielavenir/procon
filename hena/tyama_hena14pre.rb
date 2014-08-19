#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/66806c9dc14a96f2fd42
#http://nabetani.sakura.ne.jp/hena/ord14crosscircle/
STDOUT.sync=true
while gets
	l=$_.chomp.split('')
	a=l.uniq.map{|e|
		l.each_with_index.select{|f|e==f[0]}.map{|f|f[1]}
	}
	# aabbca1bcb -> [[0, 1, 5], [2, 3, 7, 9], [4, 8], [6]]
	n=0
	a.size.times{|i|
		# a[i]角形の対角線の交点の個数はa[i]C4
		n+=(a[i].size-3..a[i].size).reduce(:*)/24 if a[i].size>3
		(i+1).step(a.size-1){|j|
			a[i].combination(2){|c,d|
				a[j].combination(2){|e,f|
					e_inside=c<e&&e<d
					f_inside=c<f&&f<d
					n+=1 if e_inside^f_inside
				}
			}
		}
	}
	puts n
end