#!/usr/bin/ruby
#coding:utf-8
s=$<.read
s.force_encoding('UTF-8')
#underscore is not allowed here
puts s.scan(/(?:http|https)\:\/\/([0-9a-zA-Z\-\.]+)/).map{|_e|
	e=_e[0]
	if !e.include?('.')
		nil
	elsif e.start_with?('www')||e.start_with?('ww2')
		e[e.index('.')+1..-1]
	else
		e
	end
}.select{|e|e}.uniq.sort*';'