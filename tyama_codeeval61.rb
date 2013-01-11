#!/usr/bin/ruby
message="012222 1114142503 0313012513 03141418192102 0113 2419182119021713 06131715070119"
key="BHISOECRTMGWYVALUZDNFJKPQX"
print message.split.map{|e|
	result=''
	e.chars.each_slice(2){|f|
		idx=key.index (f.join.to_i+65).chr
		result<<(idx+65).chr
	}
	result
}.join' '