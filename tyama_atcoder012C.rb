#!/usr/bin/ruby
N=19

def checkboard(m)
	N.times{|i|
		bc2=wc2=0
		N.times{|j|
			case m[i][j]
				when 'o'
					bc2+=1
					return true if bc2>4
					wc2=0
				when 'x'
					wc2+=1
					return true if wc2>4
					bc2=0
				else
					bc2=wc2=0
			end
		}
	}
	N.times{|i|
		bc2=wc2=0
		N.times{|j|
			case m[j][i]
				when 'o'
					bc2+=1
					return true if bc2>4
					wc2=0
				when 'x'
					wc2+=1
					return true if wc2>4
					bc2=0
				else
					bc2=wc2=0
			end
		}
	}
	2.times{
		0.step(N-2){|i|
			bc2=wc2=0
			(i+1).times{|j|
				#p [i-j,j]
				case m[i-j][j]
					when 'o'
						bc2+=1
						return true if bc2>4
						wc2=0
					when 'x'
						wc2+=1
						return true if wc2>4
						bc2=0
					else
						bc2=wc2=0
				end
			}
		}
		0.step(N-1){|i|
			bc2=wc2=0
			(N-i).times{|j|
				#p [N-1-j,j+i]
				case m[N-1-j][j+i]
					when 'o'
						bc2+=1
						return true if bc2>4
						wc2=0
					when 'x'
						wc2+=1
						return true if wc2>4
						bc2=0
					else
						bc2=wc2=0
				end
			}
		}
		m=m.map{|e|e.reverse}
	}
	return false
end

m=N.times.map{gets.chomp.split('')}
bc1=m.map{|e|e.count{|f|f=='o'}}.reduce(:+)
wc1=m.map{|e|e.count{|f|f=='x'}}.reduce(:+)
if bc1-wc1!=0 && bc1-wc1!=1
	puts 'NO'
	exit
end
if bc1==0&&wc1==0
	puts 'YES'
	exit
end
finalhand = bc1-wc1==0 ? 'x' : 'o'
N.times{|i|
	N.times{|j|
		if m[i][j]==finalhand
			m[i][j]='.'
			if !checkboard(m)
				puts 'YES'
				exit
			end
			m[i][j]=finalhand
		end
	}
}
puts 'NO'