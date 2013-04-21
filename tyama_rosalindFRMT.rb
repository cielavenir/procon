#!/usr/bin/ruby
require 'bio'
Bio::NCBI.default_email='rosalind@example.com'
puts Bio::NCBI::REST.efetch(gets.chomp,:db=>'nucleotide',:rettype=>'fasta').split("\n\n").map{|fasta|
	a=fasta.split"\n"
	head=a.shift
	[head,a]
}.min_by{|e|e[1].join.size}