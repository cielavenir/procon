#!/usr/bin/ruby
if !ENV['RUBY_THREAD_VM_STACK_SIZE']
	#require 'rbconfig';RUBY=File.join(RbConfig::CONFIG['bindir'],RbConfig::CONFIG['ruby_install_name'])
	require 'rubygems';RUBY=Gem.ruby
	exec({'RUBY_THREAD_VM_STACK_SIZE'=>'100000000'},RUBY,$0)
end
N,X=gets.split.map(&:to_i)
$tree=Hash.new{|h,k|h[k]=[]}
$h=Hash.new(0)
(N-1).times{
	a,b,c=gets.split.map(&:to_i)
	$tree[a]<<[b,c]
	$tree[b]<<[a,c]
}
def d(c,p,x)
	r=$h[X^x]
	$h[x]+=1
	$tree[c].each{|e,y|r+=d(e,c,x^y) if p!=e}
	r
end
p d(1,-1,0)