#!/usr/bin/ruby
gets.to_i.times{
	p [*1..gets.to_i].reduce(1,:*).to_s.chars.map(&:to_i).reduce(:+)
}
__END__
1
100