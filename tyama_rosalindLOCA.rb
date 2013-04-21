#!/usr/bin/ruby
def maximum3(a)
	if a.size == 0 then return [nil,0] end
	ret = [a[0],0]
	1.step(a.size-1){|i|
		if ret[0] < a[i] then ret = [a[i],i] end
	}
	return ret
end

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
			z = maximum3([a[i-1][j-1]+$pam250[x[i-1].chr][y[j-1].chr], a[i-1][j]-5, a[i][j-1]-5])
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
end
$pam250=Hash.new{|h,k|h[k]={}}
strs=DATA.gets.split
strs.size.times{|i|
	a=DATA.gets.split[1..-1].map(&:to_i)
	a.size.times{|j|
		$pam250[strs[i]][strs[j]]=a[j]
	}
}
seqs=[]
seq=''
gets
while gets
	if $_[0..0]=='>'
		seqs<<seq
		seq=''
	else
		seq+=$_.chomp
	end
end
seqs<<seq
local_alignment(seqs[0],seqs[1])

__END__
   A  C  D  E  F  G  H  I  K  L  M  N  P  Q  R  S  T  V  W  Y
A  2 -2  0  0 -3  1 -1 -1 -1 -2 -1  0  1  0 -2  1  1  0 -6 -3
C -2 12 -5 -5 -4 -3 -3 -2 -5 -6 -5 -4 -3 -5 -4  0 -2 -2 -8  0
D  0 -5  4  3 -6  1  1 -2  0 -4 -3  2 -1  2 -1  0  0 -2 -7 -4
E  0 -5  3  4 -5  0  1 -2  0 -3 -2  1 -1  2 -1  0  0 -2 -7 -4
F -3 -4 -6 -5  9 -5 -2  1 -5  2  0 -3 -5 -5 -4 -3 -3 -1  0  7
G  1 -3  1  0 -5  5 -2 -3 -2 -4 -3  0  0 -1 -3  1  0 -1 -7 -5
H -1 -3  1  1 -2 -2  6 -2  0 -2 -2  2  0  3  2 -1 -1 -2 -3  0
I -1 -2 -2 -2  1 -3 -2  5 -2  2  2 -2 -2 -2 -2 -1  0  4 -5 -1
K -1 -5  0  0 -5 -2  0 -2  5 -3  0  1 -1  1  3  0  0 -2 -3 -4
L -2 -6 -4 -3  2 -4 -2  2 -3  6  4 -3 -3 -2 -3 -3 -2  2 -2 -1
M -1 -5 -3 -2  0 -3 -2  2  0  4  6 -2 -2 -1  0 -2 -1  2 -4 -2
N  0 -4  2  1 -3  0  2 -2  1 -3 -2  2  0  1  0  1  0 -2 -4 -2
P  1 -3 -1 -1 -5  0  0 -2 -1 -3 -2  0  6  0  0  1  0 -1 -6 -5
Q  0 -5  2  2 -5 -1  3 -2  1 -2 -1  1  0  4  1 -1 -1 -2 -5 -4
R -2 -4 -1 -1 -4 -3  2 -2  3 -3  0  0  0  1  6  0 -1 -2  2 -4
S  1  0  0  0 -3  1 -1 -1  0 -3 -2  1  1 -1  0  2  1 -1 -2 -3
T  1 -2  0  0 -3  0 -1  0  0 -2 -1  0  0 -1 -1  1  3  0 -5 -3
V  0 -2 -2 -2 -1 -1 -2  4 -2  2  2 -2 -1 -2 -2 -1  0  4 -6 -2
W -6 -8 -7 -7  0 -7 -3 -5 -3 -2 -4 -4 -6 -5  2 -2 -5 -6 17  0
Y -3  0 -4 -4  7 -5  0 -1 -4 -1 -2 -2 -5 -4 -4 -3 -3 -2  0 10