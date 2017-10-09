#!/usr/bin/ruby
ENV[Z='RUBY_THREAD_VM_STACK_SIZE']||exec({Z=>?5*8},'ruby',$0)
def dfs(c)
	H[c].each{|e|
	if Z[e]
		raise if (Z[c]-Z[e])%2<1
	else
		Z[e]=Z[c]+1
		dfs(e)
	end
	}
end
N,M=gets.split.map &:to_i
H=Hash.new{|h,k|h[k]=[]};Z={1=>0}
M.times{
a,b=gets.split.map &:to_i
H[a]<<b;H[b]<<a
}
p _=(dfs(1)&&Z.partition{|k,v|v%2<1}.map(&:size).reduce(:*) rescue N*~-N/2)-M
