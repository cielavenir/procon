#!/usr/bin/ruby
#RUBY_THREAD_VM_STACK_SIZE=4194304
raise "Ruby 2.0+ is required" if RUBY_VERSION<'2.0'
$memo=Hash.new{|h,k|h[k]={}}
def ack(m,n)
	return $memo[m][n] if $memo[m][n]
	return $memo[m][n]=n+1 if m==0
	return $memo[m][n]=ack(m-1,1) if n==0
	return $memo[m][n]=ack(m-1,ack(m,n-1))
end
puts RubyVM::DEFAULT_PARAMS
puts ack(4,1)