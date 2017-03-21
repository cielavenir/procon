#!/usr/bin/ruby
ENV[Z='RUBY_THREAD_VM_STACK_SIZE']||exec({Z=>?5*8},'ruby',$0)
def dfs(c)
	f=false
	$h[c].each{|d|
		if $v[d]==0
			$v[d]=3-$v[c]
			f=true if dfs(d)
		elsif $v[d]==$v[c]
			f=true
		end
	}
	f
end
n,m=gets.split.map &:to_i
$h=Hash.new{|h,k|h[k]=[]}
m.times{a,b=gets.split.map &:to_i;$h[a-1]<<b-1;$h[b-1]<<a-1}
$v=Hash.new 0
a=b=c=0
n.times{|i|
	next if $v[i]>0
	if $h[i].empty?
		c+=1
	else
		$v[i]=1
		if dfs(i)
			b+=1
		else
			a+=1
		end
	end
}
p a*a*2+a*b*2+b*b+(n*n-(n-c)*(n-c))
