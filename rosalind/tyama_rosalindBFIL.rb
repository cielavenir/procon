#!/usr/bin/ruby
require 'bio'
threshold,percentage=gets.split.map(&:to_i)
$<.each_slice(4){|a|
	fastq=Bio::Fastq.new(a*"\n")
	fastq.format=:fastq_sanger #phred33
	idx=fastq.quality_scores.index{|e|e>=threshold}
	ridx=fastq.quality_scores.rindex{|e|e>=threshold}
	puts a[0]
	puts a[1][idx..ridx]
	puts a[2]
	puts a[3][idx..ridx]
}