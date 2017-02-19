#!/usr/bin/ruby
#if !ENV['RUBY_THREAD_VM_STACK_SIZE']
	#require 'rbconfig';RUBY=File.join(RbConfig::CONFIG['bindir'],RbConfig::CONFIG['ruby_install_name'])
#	require 'rubygems';RUBY=Gem.ruby
#	exec({'RUBY_THREAD_VM_STACK_SIZE'=>'100000000'},RUBY,$0)
#end
ENV[Z='RUBY_THREAD_VM_STACK_SIZE']||exec({Z=>?5*8},'ruby',$0)
N,X=gets.split.map &:to_i
T=Hash.new{|h,k|h[k]=[]}
H=Hash.new 0
(N-1).times{a,b,c=gets.split.map &:to_i;T[a]<<[b,c];T[b]<<[a,c]}
def d(c,p,x)
	r=H[X^x]
	H[x]+=1
	T[c].map{|e,y|r+=d e,c,x^y if p!=e}
	r
end
p d 1,-1,0
