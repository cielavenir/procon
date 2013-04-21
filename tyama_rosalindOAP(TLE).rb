#!/usr/bin/ruby
def maximum3(a)
	if a.size == 0 then return [nil,0] end
	ret = [a[0],0]
	1.step(a.size-1){|i|
		if ret[0] < a[i] then ret = [a[i],i] end
	}
	return ret
end

def alignment(x, y)
	#initialize
	a = Array.new(x.size+1){Array.new(y.length+1, 0)}
	back = Array.new(x.size+1){Array.new(y.length+1, 0)}
	tx = ""; ty = ""; t=""

	#DP
	1.step(a.size-1){|i| a[i][0] = a[i-1][0] - 0;back[i][0]=[i-1,0,  "a"]}
	1.step(a[0].size-1){|j| a[0][j] = a[0][j-1] - 2;back[0][j]=[0,  j-1,"b"]}
	1.step(a.size-1){|i|
	#STDERR.puts i
		1.step(a[0].size-1){|j|
			z = maximum3([x[i-1] == y[j-1] ? a[i-1][j-1]+1 : a[i-1][j-1]-2, a[i-1][j]-2, a[i][j-1]-2])
			a[i][j]=z[0];
			case z[1]
				when 0 then back[i][j]=[i-1,j-1,"c"]
				when 1 then back[i][j]=[i-1,j,  "a"]
				when 2 then back[i][j]=[i,  j-1,"b"]
			end
		}
	}
	#trace-back
	z=maximum3(a.last)
	n=x.size;m=z[1]
	while n!=0||m!=0 do
		t+=back[n][m][2]
		n,m = back[n][m][0],back[n][m][1]
	end
	t.reverse!

	#output
	i=0;j=0
	t.chars{|c|
		case c
			when "c" then tx+=x[i].chr; i+=1; ty+=y[j].chr; j+=1;
			when "a" then tx+=x[i].chr; i+=1; ty+="-";
			when "b" then tx+="-";            ty+=y[j].chr; j+=1;
		end
	}

	p a[x.size][z[1]]
	ty=~/^(-*)/
	startgap=$1
	puts tx[startgap.size..-1]
	puts ty[startgap.size..-1]
end

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
p alignment(seqs[0],seqs[1])