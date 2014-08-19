#!/usr/bin/ruby
require 'prime'

M=1000001
M.step(1/0.0,2){|n|
	n=n.to_i
	if n.prime? || n%5==0 then next end # || n%2==0
	x,k=1,1
	while x>0 do x=(x*10+1)%n;k+=1 end
	if k>=M then p n;exit end
}