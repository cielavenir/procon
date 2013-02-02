#!/usr/bin/ruby
require 'bio'
Bio::NCBI.default_email='rosalind@example.com'
p Bio::NCBI::REST.esearch(%Q(("#{gets.chomp}"[Organism]) AND ("#{gets.chomp}"[Publication Date]:"#{gets.chomp}"[Publication Date])),:db=>'nucleotide').size