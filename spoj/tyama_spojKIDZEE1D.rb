#!/usr/bin/ruby
raise if RUBY_VERSION<'1.9'
T={
	80=>'A+',
	75=>'A',
	70=>'A-',
	65=>'B+',
	60=>'B',
	55=>'B-',
	50=>'C',
	45=>'D',
	0=>'F',
}
gets.to_i.times{|i|
	n=gets.to_i
	puts "Case #{i+1}: #{T.find{|k,v|k<=n}.last}"
}