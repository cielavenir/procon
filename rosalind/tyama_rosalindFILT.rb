#!/usr/bin/ruby
require 'bio'
threshold,percentage=gets.split.map(&:to_i)
p $<.each_slice(4).count{|a|
	fastq=Bio::Fastq.new(a*"\n")
	fastq.format=:fastq_sanger #phred33
	fastq.quality_scores.count{|e|
		e>=threshold
	}*100>=fastq.quality_scores.size*percentage
}