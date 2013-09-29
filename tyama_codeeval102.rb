#!/usr/bin/ruby
require 'json'
puts $<.map{|line|
	n=0
	json=JSON.parse(line)['menu']['items']
	json.size.times{|i|if json[i]&&json[i]['label'] then n+=json[i]['id'] end}
	n
}