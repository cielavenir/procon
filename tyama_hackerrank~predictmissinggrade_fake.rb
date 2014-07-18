#!/usr/bin/ruby
require 'json'
gets.to_i.times{
	json=JSON.parse(gets)
	n=0
	json.each{|k,v|n+=v if k!='serial'}
	puts n/(json.size-1)
}