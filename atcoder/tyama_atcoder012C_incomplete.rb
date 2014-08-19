#!/usr/bin/ruby
N=19
m1=N.times.map{gets.chomp.split('')}
	
bc1=m1.map{|e|e.count{|f|f=='o'}}.reduce(:+)
wc1=m1.map{|e|e.count{|f|f=='x'}}.reduce(:+)
bw=ww=false
bwx=wwx=false
N.times{|i|
	bc2=wc2=0
	N.times{|j|
		case m1[i][j]
			when 'o'
				bc2+=1
				if bc2>4
					if bwx then puts 'NO';exit end
					bw=true
				end
				if bc2>9 then puts 'NO';exit end
				wc2=0
				wwx=true if ww
			when 'x'
				wc2+=1
				if wc2>4
					if wwx then puts 'NO';exit end
					ww=true
				end
				if wc2>9 then puts 'NO';exit end
				bc2=0
				bwx=true if bw
			else
				bc2=wc2=0
				bwx=true if bw
				wwx=true if ww
		end
	}
				bc2=wc2=0
				bwx=true if bw
				wwx=true if ww
}
N.times{|i|
	bc2=wc2=0
	N.times{|j|
		case m1[j][i]
			when 'o'
				bc2+=1
				if bc2>4
					if bwx then puts 'NO';exit end
					bw=true
				end
				if bc2>9 then puts 'NO';exit end
				wc2=0
				wwx=true if ww
			when 'x'
				wc2+=1
				if wc2>4
					if wwx then puts 'NO';exit end
					ww=true
				end
				if wc2>9 then puts 'NO';exit end
				bc2=0
				bwx=true if bw
			else
				bc2=wc2=0
				bwx=true if bw
				wwx=true if ww
		end
	}
				bc2=wc2=0
				bwx=true if bw
				wwx=true if ww
}

2.times{
0.step(18){|i|
	bc2=wc2=0
	(i+1).times{|j|
	#p [i-j,j]
		case m1[i-j][j]
			when 'o'
				bc2+=1
				if bc2>4
					if bwx then puts 'NO';exit end
					bw=true
				end
				if bc2>9 then puts 'NO';exit end
				wc2=0
				wwx=true if ww
			when 'x'
				wc2+=1
				if wc2>4
					if wwx then puts 'NO';exit end
					ww=true
				end
				if wc2>9 then puts 'NO';exit end
				bc2=0
				bwx=true if bw
			else
				bc2=wc2=0
				bwx=true if bw
				wwx=true if ww
		end
	}
				bc2=wc2=0
				bwx=true if bw
				wwx=true if ww
}
0.step(18){|i|
	bc2=wc2=0
	(19-i).times{|j|
	#p [18-j,j+i]
		case m1[18-j][j+i]
			when 'o'
				bc2+=1
				if bc2>4
					if bwx then puts 'NO';exit end
					bw=true
				end
				if bc2>9 then puts 'NO';exit end
				wc2=0
				wwx=true if ww
			when 'x'
				wc2+=1
				if wc2>4
					if wwx then puts 'NO';exit end
					ww=true
				end
				if wc2>9 then puts 'NO';exit end
				bc2=0
				bwx=true if bw
			else
				bc2=wc2=0
				bwx=true if bw
				wwx=true if ww
		end
	}
				bc2=wc2=0
				bwx=true if bw
				wwx=true if ww
}
m1=m1.map{|e|e.reverse}
}

if bw&&ww then puts 'NO';exit end
if bc1!=wc1&&bc1-1!=wc1 then puts 'NO';exit end
if bc1==wc1&&bw then puts 'NO';exit end
if bc1==wc1-1&&ww then puts 'NO';exit end
puts 'YES'
__END__
WA:
.o.......
ooooooooo
.o.......
.o.......
.o.......
.o.......
.o.......
.o.......
.o.......