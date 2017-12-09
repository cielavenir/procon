#!/usr/bin/ruby
ENV[Z='RUBY_THREAD_VM_STACK_SIZE']||exec({Z=>?5*8},'ruby',$0)
N,M=gets.split.map &:to_i
H=Hash.new{|h,k|h[k]=[]}
M.times{a,b=gets.split.map &:to_i;H[a]<<b;H[b]<<a}
V=[1,1,1]
def r s;z=1;H[s].each{|e|!V[e]&&(V[e]=1;z+=r e)};z end
g=[r(1),r(2)].min
p N*~-N/2-g*(N-g)-M
