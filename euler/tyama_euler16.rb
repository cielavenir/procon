#!/usr/bin/ruby
gets.to_i.times{
	p (2**gets.to_i).to_s.chars.map(&:to_i).reduce(:+)
}
__END__
1
1000