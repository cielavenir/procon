#!/usr/bin/ruby
require 'bio'
Bio::NCBI.default_email='rosalind@example.com'
puts Bio::NCBI::REST.esearch(%Q(("#{gets.chomp}"[Author]) AND ("#{gets.chomp}"[dp])),:db=>'pubmed',:sort=>'PublicationDate').last