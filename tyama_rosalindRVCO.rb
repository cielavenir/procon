#!/usr/bin/ruby
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
p seqs.count{|e|e==e.reverse.tr('ATGC','TACG')}