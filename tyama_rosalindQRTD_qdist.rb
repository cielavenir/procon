#!/usr/bin/ruby
#prepare http://birc.au.dk/software/qdist/
require 'tempfile'
QDIST='qdist'
Tempfile.open('fasta1','.'){|fasta1|
Tempfile.open('fasta2','.'){|fasta2|
	gets
	fasta1.puts gets
	fasta1.flush
	fasta2.puts gets
	fasta2.flush
	io=open(%Q(| "#{QDIST}" #{File.basename fasta1.path} #{File.basename fasta2.path}))
	io.gets
	q=io.gets.split[6].to_i
	puts q*2
}}