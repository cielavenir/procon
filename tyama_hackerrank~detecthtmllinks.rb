#!/usr/bin/ruby
$<.read.scan(/\<a href="(.+?)".*?\>(.*?)\<\/a\>/).each{|a,b|
	b=b.gsub(/\<.+?\>/,'').strip
	puts [a,b]*','
}