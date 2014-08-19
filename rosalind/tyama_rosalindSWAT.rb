#!/usr/bin/ruby
#prepare emboss water
#SWAT
PARAM=[10,1,'EBLOSUM62']
require 'tempfile'
WATER='water'
require 'mechanize'
mech=Mechanize.new
seqs=gets.split.map{|e|
	mech.get('http://www.uniprot.org/uniprot/'+e+'.fasta')
	mech.page.body
}
Tempfile.open('fasta1','.'){|fasta1|
Tempfile.open('fasta2','.'){|fasta2|
	fasta1.puts "#{seqs[0]}"
	fasta1.flush
	fasta2.puts "#{seqs[1]}"
	fasta2.flush
	io=open(%Q(| "#{WATER}" -gapopen #{PARAM[0]} -gapextend #{PARAM[1]} -datafile #{PARAM[2]} -outfile stdout "#{File.basename fasta1.path}" "#{File.basename fasta2.path}"))
	until (l=io.gets)=~/Length/ do; end
	l=~/(\d+)/
	len=$1.to_i
	until (l=io.gets)=~/Score/ do; end
	l=~/(-?\d+)/
	puts $1
=begin
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
=end
}}