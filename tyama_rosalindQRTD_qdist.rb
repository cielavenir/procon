#!/usr/bin/ruby
#prepare http://birc.au.dk/software/qdist/
require 'tempfile'
QDIST='qdist'
Tempfile.open('tree1','.'){|tree1|
Tempfile.open('tree2','.'){|tree2|
	gets
	tree1.puts gets
	tree1.flush
	tree2.puts gets
	tree2.flush
	io=open(%Q(| "#{QDIST}" #{File.basename tree1.path} #{File.basename tree2.path}))
	io.gets
	q=io.gets.split[6].to_i
	puts q*2
}}