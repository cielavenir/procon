#!/usr/bin/ruby
ENV[Z='RUBY_THREAD_VM_STACK_SIZE']||exec({Z=>?5*8},'ruby',$0)
M={0=>0}
def C n;M[n]||=C(m=P/-~(P/n))+(P%n+P%-~m)*(n-m)/2 end
P=gets.to_i
$<.map{|e|l,r=e.split.map &:to_i;p C(r)-C(l-1)}
