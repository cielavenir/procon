#!/usr/bin/ruby
require 'json'
M=10**9+7
bse=100000
v=[r=1]
M.times{|i|
	r=r*(i+1)%M
	if (i+1)%bse==0
		v<<r
	end
}
puts JSON.generate v
