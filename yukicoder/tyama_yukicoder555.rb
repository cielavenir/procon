#!/usr/bin/ruby
ENV[Z='RUBY_THREAD_VM_STACK_SIZE']||exec({Z=>?5*8},'ruby',$0)
M={}
def f a,b
M[[a,b]]||=a<N ? [f(2*a,a)+C,f(a+b,b)].min+V : C
end
N,C,V=$<.read.split.map &:to_i
p f 1,1
