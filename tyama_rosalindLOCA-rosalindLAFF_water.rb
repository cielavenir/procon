#!/usr/bin/ruby
#prepare emboss water
#LAFF
PARAM=[11,1,'EBLOSUM62']
#LOCA
#PARAM=[5,5,'EPAM250']
require 'tempfile'
WATER='water'
seqs=[]
seq=''
gets
while gets
	if $_[0..0]=='>'
		seqs<<seq
		seq=''
	else
		seq+=$_.chomp
	end
end
seqs<<seq
Tempfile.open('fasta1','.'){|fasta1|
Tempfile.open('fasta2','.'){|fasta2|
	fasta1.puts ">1\n#{seqs[0]}"
	fasta1.flush
	fasta2.puts ">2\n#{seqs[1]}"
	fasta2.flush
	io=open(%Q(| "#{WATER}" -gapopen #{PARAM[0]} -gapextend #{PARAM[1]} -datafile #{PARAM[2]} -outfile stdout "#{File.basename fasta1.path}" "#{File.basename fasta2.path}"))
	until (l=io.gets)=~/Length/ do; end
	l=~/(\d+)/
	len=$1.to_i
	until (l=io.gets)=~/Score/ do; end
	l=~/(-?\d+)/
	puts $1
	seqs=[]
	until io.eof?
		l=io.gets
		if l=~/([-A-Z]+)/
			seqs<<$1
		end
	end
	seqs.each_slice(2).to_a.transpose.each{|e|
		puts e.join[0,len].tr('-','')
	}
}}