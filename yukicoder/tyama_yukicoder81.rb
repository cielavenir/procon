#!/usr/bin/ruby
require 'bigdecimal'
s=BigDecimal.new(0)
gets.to_i.times{
	s+=BigDecimal.new(gets.chomp)
}
st=s.to_s('f')
l=st.split('.')[1].size
puts st+'0'*(10-l)