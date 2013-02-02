#!/usr/bin/ruby
require 'bio'
Bio::NCBI.default_email='rosalind@example.com'
a=Bio::NCBI::REST.efetch(gets.chomp,:db=>'nucleotide',:rettype=>'fasta').split("\n\n").map{|fasta|
	a=fasta.split"\n"
	head=a.shift
	[head,a]
}
r=a.sort_by{|e|e[1].join.length}[0]
puts r[0]
puts r[1]