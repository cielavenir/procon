#!/usr/bin/ruby
require 'json'
gets.to_i.times{
	json=JSON.parse(gets)
	n=0.0
	json.each{|k,v|n+=v**2 if k!='serial'}
	puts Math.sqrt(n/(json.size-1)).round
}