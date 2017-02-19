#!/usr/bin/ruby
ENV[Z='RUBY_THREAD_VM_STACK_SIZE']||exec({Z=>?5*8},'ruby',$0)
def f(i,c)(h=(H[i].map{|e|f e,i}.max||0)+1)>=K&&c!=1&&(h=0;$r+=1);h end
N,K,Q,*A=`dd`.split.map &:to_i
H=Hash.new{|h,k|h[k]=[]}
2.upto(N){|i|H[A[i-$r=2]]<<i}
f 1,1;p$r--~Q/Q
