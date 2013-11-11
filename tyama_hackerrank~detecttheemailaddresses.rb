#!/usr/bin/ruby
#coding:utf-8
s=$<.read
s.force_encoding('UTF-8')
puts s.scan(/[0-9a-zA-Z\-\_\.]+\@[0-9a-zA-Z\-\_\.]+/).map{|_e|
	_e.sub(/\.+$/,'')
}.uniq.sort*';'