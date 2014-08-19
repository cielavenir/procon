#!/usr/bin/ruby
require 'bio'
Bio::NCBI.default_email='rosalind@example.com'
p Bio::NCBI::REST.esearch(%Q(("srcdb_refseq"[Properties]) AND ("#{gets.chomp}"[Organism]) AND ("#{gets.chomp}"[SLEN]:"#{gets.chomp}"[SLEN]) AND ("0"[PDAT]:"#{gets.chomp}"[PDAT])),{:db=>'nucleotide'},0).size