#!/usr/bin/ruby
#prepare emboss needle
#GAFF
PARAM=[12,1]
#GCON
#PARAM=[5,0]
#GLOB
#PARAM=[5,5]
require 'tempfile'
NEEDLE='needle'
Tempfile.open('fasta1','.'){|fasta1|
Tempfile.open('fasta2','.'){|fasta2|
	fasta1.puts ">1\n#{gets.chomp}"
	fasta1.flush
	fasta2.puts ">2\n#{gets.chomp}"
	fasta2.flush
	io=open(%Q(| "#{NEEDLE}" -gapopen #{PARAM[0]} -gapextend #{PARAM[1]} -endweight -endopen #{PARAM[0]} -endextend #{PARAM[1]} -outfile stdout "#{File.basename fasta1.path}" "#{File.basename fasta2.path}"))
	until (l=io.gets)=~/Length/ do; end
	l=~/(\d+)/
	len=$1.to_i
	until (l=io.gets)=~/Score/ do; end
	l=~/(-?\d+)/
	puts $1
=begin
	seqs=[]
	until io.eof?
		l=io.gets
		if l=~/([-A-Z]+)/
			seqs<<$1
		end
	end
	seqs.each_slice(2).to_a.transpose.each{|e|
		puts e.join[0,len]
	}
=end
}}