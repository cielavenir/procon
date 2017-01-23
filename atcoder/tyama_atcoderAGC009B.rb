#!/usr/bin/ruby
#if !ENV['RUBY_THREAD_VM_STACK_SIZE']
	#require 'rbconfig';RUBY=File.join(RbConfig::CONFIG['bindir'],RbConfig::CONFIG['ruby_install_name'])
#	require 'rubygems';RUBY=Gem.ruby
#	exec({'RUBY_THREAD_VM_STACK_SIZE'=>'50000000'},RUBY,$0)
#end
ENV[Z='RUBY_THREAD_VM_STACK_SIZE']||exec({Z=>'50000000'},'ruby',$0)
def f(i)a=H[i].map{|e|-f(e)}.sort;(1..a.size).map{|i|i-a[i-1]}.max||0end
H=Hash.new{|h,k|h[k]=[]};2.upto(gets.to_i){|i|H[gets.to_i]<<i};p f 1
