#!/usr/bin/ruby
ENV[Z='RUBY_THREAD_VM_STACK_SIZE']||exec({Z=>?5*8},'ruby',$0)
R=Hash.new 0
E=Hash.new{|h,k|h[k]=[]}
def f(x,q)
	E[x].each{|v|(f(v,x);R[x]^=R[v]+1)if v!=q}
end
gets;$<.each{|e|
	u,v=e.split.map &:to_i
	E[u]<<v;E[v]<<u
}
f(1,0)
puts R[1]>0 ? :Alice : :Bob
