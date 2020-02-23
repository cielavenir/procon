#!/usr/bin/env crystal
a=ARGF.gets_to_end.split.map &.to_i
t,b=a.shift 2
a.each{|e|
	e<1&&(p 0;next)
	puts String.build{|s|
		while e!=0
			s<<(e%-b).to_s
			e//=-b
			e=-e
		end
	}.reverse
}
