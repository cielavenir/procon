#!/usr/bin/ruby
T=[*'A'..'Z']
def zip(a) a.shift.zip(*a) end
gets.to_i.times{
	key=gets.chomp.split('').uniq
	t=zip((key+(T-key)).each_slice(key.size).to_a).sort*''
	puts gets.tr(t,'A-Z')
}