#!/usr/bin/ruby
seqs=[]
seq=''
gets
while gets
	if $_[0]=='>'
		seqs<<seq
		seq=''
	else
		seq+=$_.chomp
	end
end
seqs<<seq
transition=0
transversion=0
seqs[0].split('').zip(seqs[1].split('')).each{|a,b|
	[['A','G'],['G','A'],['C','T'],['T','C']].include?([a,b]) ? transition+=1 : transversion+=1 if a!=b
}
p transition.to_f/transversion