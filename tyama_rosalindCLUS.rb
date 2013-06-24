#!/usr/bin/ruby
#prepare clustalw
require 'tempfile'
CLUSTALW='clustalw'
require 'bio'
Tempfile.open('fasta','.'){|fasta|
Tempfile.open('dnd','.'){|dnd|
	fasta.puts $<.read
	fasta.flush
	dnd.close
	system(%Q("#{CLUSTALW}" -infile=#{File.basename fasta.path} -newtree=#{File.basename dnd.path} -align -type=dna -ktuple=1 -window=5 -score=percent -topdiags=5 -pairgap=3 -pwmatrix=gonnet -pwdnamatrix=iub -pwgapopen=10 -pwgapext=0.1 -matrix=gonnet -dnamatrix=iub -gapopen=10 -gapext=0.2 -gapdist=5 -iteration=none -numiter=1 -clustering=NJ -seqnos=on -outorder=aligned -outfile=/dev/null 2>/dev/null >/dev/null))
	tree=Bio::FlatFile.open(Bio::Newick,File.basename(dnd.path)).next_entry.tree
	puts tree.leaves.map{|leaf|
		[tree.distance(leaf,tree.root),leaf.name.tr(' ','_')]
	}.max[1]
}}