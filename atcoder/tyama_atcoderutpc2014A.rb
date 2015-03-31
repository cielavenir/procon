#!/usr/bin/ruby
a=gets.split
while idx=(a.size-2).times.find{|i|
	a[i]=='not'&&a[i+1]=='not'&&a[i+2]!='not'
}
	a=a[0,idx]+a[idx+2..-1]
end
puts a*' '