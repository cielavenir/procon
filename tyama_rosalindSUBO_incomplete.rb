#!/usr/bin/ruby
#prepare fasta lalign
#PARAM=[]
require 'tempfile'
LALIGN='lalign35'
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
	io=open(%Q(| "#{LALIGN}" -n -m4 "#{File.basename fasta1.path}" "#{File.basename fasta2.path}"))
	io.select{|e|
		if e=~/(\d+)-(\s*?)(\d+)/
			l=$3.to_i-$1.to_i
			if 29<l && l<41
				p l
			end
		end
	}
	puts "---"
	io=open(%Q(| "#{LALIGN}" -n -m4 "#{File.basename fasta2.path}" "#{File.basename fasta1.path}"))
	io.select{|e|
		if e=~/(\d+)-(\s*?)(\d+)/
			l=$3.to_i-$1.to_i
			if 29<l && l<41
				p l
			end
		end
	}
}}