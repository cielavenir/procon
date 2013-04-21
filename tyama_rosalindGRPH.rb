#!/usr/bin/ruby
seqs=[]
names=[gets.chomp[1..-1]]
seq=''
while gets
	if $_[0..0]=='>'
		seqs<<seq
		names<<$_.chomp[1..-1]
		seq=''
	else
		seq+=$_.chomp
	end
end
seqs<<seq
seqs.size.times{|i|
	seqs.size.times{|j|
		next if i==j
		puts "#{names[i]} #{names[j]}" if seqs[i][-3..-1]==seqs[j][0..2]
	}
}