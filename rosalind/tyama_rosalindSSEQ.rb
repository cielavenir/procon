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
i=0
puts seqs[1].chars.map{|e|i=seqs[0].index(e,i)+1}*' '