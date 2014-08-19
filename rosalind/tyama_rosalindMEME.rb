#!/usr/bin/ruby
#prepare meme
require 'tempfile'
require 'fileutils'
MEME='meme'
FileUtils.remove_entry_secure('meme_out') if File.exists?('meme_out')
Tempfile.open('fasta','.'){|fasta|
	fasta.puts $<.read
	fasta.flush
	system(%Q("#{MEME}" #{File.basename fasta.path} -protein))
	lines=[]
	flg=false
	File.open('meme_out/meme.txt'){|f|
		while(line=f.gets)
			line.chomp!
			flg=true if line.start_with?('Multilevel')
			if flg
				break if line.start_with?('----------')
				lines<<line.split('')
			end
		end
	}
	# [Mcs][uoe][lnq][tsu][iee][lnn][esc][vue][es]l[][][][][][][][][][][]VLVYCMHNKLLGQGA[RLW][FL]V[NK]NCGMLVGVLSSAGATVRMI
	regex=lines.transpose.map{|e|
		s=e.join.strip
		s.size==1 ? s : '['+s+']'
	}*''
	# VLVYCMHNKLLGQGA[RLW][FL]V[NK]NCGMLVGVLSSAGATVRMI
	puts regex[regex.rindex('[]')+2..-1]
}
FileUtils.remove_entry_secure('meme_out')