#!/usr/bin/ruby
#if !ENV['RUBY_THREAD_VM_STACK_SIZE']
	#require 'rbconfig';RUBY=File.join(RbConfig::CONFIG['bindir'],RbConfig::CONFIG['ruby_install_name'])
#	require 'rubygems';RUBY=Gem.ruby
#	exec({'RUBY_THREAD_VM_STACK_SIZE'=>'50000000'},RUBY,$0)
#end
ENV[Z='RUBY_THREAD_VM_STACK_SIZE']||exec({Z=>?5*8},'ruby',$0)
def f(i)r=0;H[i].map{|e|f e}.sort.map{|e|r=[r,e].max+1};r end
H=Hash.new{|h,k|h[k]=[]};2.upto(gets.to_i){|i|H[gets.to_i]<<i};p f 1
