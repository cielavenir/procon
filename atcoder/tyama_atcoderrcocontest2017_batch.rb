#!/usr/bin/ruby
[*1..20].each{|i|
	system('java Generator -seed %d > %d.in'%[i,i])
	system('~/procon/a.out < %d.in > %d.out'%[i,i])
	system('java Judge %d.in %d.out'%[i,i])
}
