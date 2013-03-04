#!/usr/bin/ruby
#prepare emboss needle
#NEED
PARAM=[12,1]
require 'tempfile'
NEEDLE='needle'
require 'bio'
Bio::NCBI.default_email='rosalind@example.com'
a=Bio::NCBI::REST.efetch(gets.chomp,:db=>'nucleotide',:rettype=>'fasta').split("\n\n")
Tempfile.open('fasta1','.'){|fasta1|
Tempfile.open('fasta2','.'){|fasta2|
	fasta1.puts a[0]
	fasta1.flush
	fasta2.puts a[1]
	fasta2.flush
	io=open(%Q(| "#{NEEDLE}" -gapopen #{PARAM[0]} -gapextend #{PARAM[1]} -endweight -endopen #{PARAM[0]} -endextend #{PARAM[1]} -datafile EDNAFULL -outfile stdout "#{File.basename fasta1.path}" "#{File.basename fasta2.path}"))
	#puts io.read;exit
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