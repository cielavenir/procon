#!/usr/bin/ruby
#coding:utf-8
require 'net/http'
require 'uri'
puts Net::HTTP.get(URI.parse 'http://en.wikipedia.org/wiki/RSA_numbers').split('1143816257578888676')[1].split('</pre>')[1].split('=')[1].split("\n").map{|e|e.tr('^0-9','')}
__END__
3490529510847650949147849619903898133417764638493387843990820577
32769132993266709549961988190834461413177642967992942539798288533