n=0
N=M=6
def rec(x,y)
	if 0<=x&&x<N&&0<=y&&y<M&&$a[y][x]>0
		$a[y][x]=0;rec(x-1,y);rec(x+1,y);rec(x,y-1);rec(x,y+1)
	end
end
$a=a
M.times{|i|N.times{|j|if $a[i][j]>0 then n+=1;rec(j,i) end}}