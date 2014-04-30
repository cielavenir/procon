#!/usr/bin/ruby
#coding:utf-8
raise 'Ruby 1.9+ required' if RUBY_VERSION<'1.9'
Encoding.default_external='Windows-31J'
a=$<.drop(1).map{|e|
	e.split(',')[3,2]
}.transpose
r=0
a.each{|b|
	b.each{|e|
		s=e.split('')
		1.step(s.size-1){|i|
			if b.count{|f|f.start_with?(s[0,i]*'')}==1
				r+=i
				break
			end
		}
	}
}
puts r.to_s+'文字'
#をぐらやま等が本来と異なる字数になる問題は考慮していない