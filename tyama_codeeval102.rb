#!/usr/bin/ruby
require 'json'
puts $<.map{|line|
	json=JSON.parse(line)
	json['menu']['items'].select{|e|e&&e['label']}.map{|e|e['id']}.reduce(:+)||0
}