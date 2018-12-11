#!/usr/bin/ruby
ENV[Z='RUBY_THREAD_VM_STACK_SIZE']||exec({Z=>?5*8},'ruby',$0)
h=Hash.new{|h,k|h[k]=[]}
v={}
r=0
f=->j{a=true;v[j]=1;h[j].each{|e|!v[e]&&f[e]&&a=false};a&&r+=1;a}
gets;$<.each{|e|a,b=e.split.map &:to_i;h[a]<<b;h[b]<<a}
f[1];p r
