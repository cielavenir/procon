#!/usr/bin/ruby
ENV[A='RUBY_THREAD_VM_STACK_SIZE']||exec({A=>?5*8},'ruby',$0)
F=->c{H[c].all?{|e|Z[e]?Z[c]^Z[e]>0:(Z[e]=1^Z[c];F[e])}}
N,M=gets.split.map &:to_i;H=Hash.new{|h,k|h[k]=[]};Z={1=>0}
$<.map{|e|a,b=e.split.map &:to_i;H[a]<<b;H[b]<<a}
p (F[1]?(x,y=Z.partition{|k,v|v>0};x.size*y.size):N*~-N/2)-M
