#!/usr/bin/ruby
require 'prime'
N=gets.to_i
$a=[]
s=1
Prime.each{|e|
	$a<<e
	break if (s*=3)>=N*2-1
}

def dfs(r,v,d,x)
	return Float::INFINITY if $a[d]**x>400
	if (v*(x*2+1)+1)/2>=N
		return r*$a[d]**x
	end
	return [dfs(r,v,d,x+1),dfs(r*$a[d]**x,v*(x*2+1),d+1,1)].min
end
p dfs(1,1,0,1)
__END__
1001
4000001