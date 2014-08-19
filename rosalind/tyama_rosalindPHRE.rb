#!/usr/bin/ruby
require 'bio'
class Array
	def average
		self.reduce(:+)/self.size.to_f
	end
end
threshold=gets.to_i
p $<.each_slice(4).count{|a|
	fastq=Bio::Fastq.new(a*"\n")
	fastq.format=:fastq_sanger #phred33
	fastq.quality_scores.average<threshold
}