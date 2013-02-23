#!/usr/bin/ruby
#prepare http://www.ncbi.nlm.nih.gov/CBBresearch/Schaffer/msa.html
require 'tempfile'
MSA='msa'
Tempfile.open('fasta','.'){|fasta|
	seqs=ARGF.map(&:chomp)
	seqs.each_with_index{|e,i|fasta.puts ">#{i}\n#{e}"}
	Tempfile.open('cost','.'){|cost|
		s='-ACDEFGHIKLMNPQRSTVWY'
		cost.puts 0
		s.chars{|e|
			s.chars{|f|
				cost.puts "#{e} #{f} #{e==f ? 0 : 1}"
			}
		}
		fasta.flush
		cost.flush
		io = open(%Q(| "#{MSA}" -o -b -g -c "#{File.basename cost.path}" "#{File.basename fasta.path}"))
		until io.gets=~/Optimal/ do; end
		io.gets
		seqs=seqs.length.times.map{io.gets.chomp}
		io.gets
		io.gets
		io.gets
		io.gets=~/(\d+)/
		puts "-"+$1
		puts seqs*"\n"
	}
}