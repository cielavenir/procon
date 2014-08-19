#!/usr/bin/ruby
#prepare fasta lalign
#PARAM=[]
require 'tempfile'
LALIGN='lalign36'
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
	io=open(%Q(| "#{LALIGN}" "#{File.basename fasta1.path}" "#{File.basename fasta2.path}"))
	a=io.select{|e|e=~/identity/}
	#puts a;exit
	a=a.select{|e|
		e=~/^(\d+).+% identity.+(\d)+ nt/ && $1.to_i>=90 && $2.to_i <= 50
	}
	s=[];t=[]
	a.each{|e| #This code is somehow broken. I need to fix.
		e=~/\((\d+)-(\d+):(\d+)-(\d+)\)$/
		i=$1.to_i;j=$2.to_i
		s<<[i,j] if s.all?{|e|j<e[0]||e[1]<i}
		i=$3.to_i;j=$4.to_i
		t<<[i,j] if t.all?{|e|j<e[0]||e[1]<i}
	}
	puts "#{s.size} #{t.size}"
}}