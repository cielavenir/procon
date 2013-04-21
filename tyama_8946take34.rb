#!/usr/bin/ruby
key='hackerschool'.split('').uniq
key_sort=key.sort
key_idx=key.map{|e|key_sort.index(e)}
#p key_idx

#http://ja.wikipedia.org/wiki/ADFGVX%E6%9A%97%E5%8F%B7
#stage1: make convertion matrix
passages=[
	{:raw=>'abcdelmnos12345678',:phase2=>'FFGVGDGXFVVAAAAGDGXXVAVGXAFXXGDXAGVD'},
	{:raw=>'whitehackerzto8946',:phase2=>'VDAXDGGGAFFVVAVAGAFXVXAAVDVXVFFVFXFG'},
]
matrix=Hash.new{|h,k|h[k]={}}
passages.each{|q|
	phase2_array=q[:phase2].split('')
	row_size_min=phase2_array.size/key_idx.size
	row_size_max=(phase2_array.size+key_idx.size-1)/key_idx.length
	row_size=[row_size_min]*key_idx.size
	(phase2_array.size%key_idx.size).times{|i|row_size[i]+=1}
	transarray=key_idx.size.times.map{|i|
		row=phase2_array.shift(row_size[key_idx.index(i)])
		if row.size<row_size_max then row<<' ' end
		row
	}
	phase1=key_idx.map{|e|transarray[e]}.transpose.map(&:join).join.strip
	#phase1.split('').each_slice(key_idx.size){|e|puts e*''};puts
	phase1.split('').each_slice(2).each_with_index{|e,i|
		#puts e.join+' '+q[:raw][i,1]
		raise e.join+' '+q[:raw][i,1] if matrix[e[0]][e[1]]&&matrix[e[0]][e[1]]!=q[:raw][i,1]
		matrix[e[0]][e[1]]=q[:raw][i,1]
	}
}
=begin
'ADFGVX'.chars{|e|
	'ADFGVX'.chars{|f|
		print matrix[e][f]||' '
	}
	puts
}
list={}
'ADFGVX'.chars{|e|
	'ADFGVX'.chars{|f|
		list[matrix[e][f]]=1 if matrix[e][f]
	}
}
unused='abcdefghijklmnopqrstuvwxyz0123456789'.chars.select{|e|!list[e]}
=end

#stage2: solve
problem='GGAGAXVAGGVAGAVAFAGGFGVAAFGAGAGGGDFAAGAGDADVFGAXAAFAGD'
phase2_array=problem.split('')
row_size_min=phase2_array.size/key_idx.size
row_size_max=(phase2_array.size+key_idx.size-1)/key_idx.length
row_size=[row_size_min]*key_idx.size
(phase2_array.size%key_idx.size).times{|i|row_size[i]+=1}
transarray=key_idx.size.times.map{|i|
	row=phase2_array.shift(row_size[key_idx.index(i)])
	if row.size<row_size_max then row<<' ' end
	row
}
phase1=key_idx.map{|e|transarray[e]}.transpose.map(&:join).join.strip
#phase1.split('').each_slice(key_idx.size){|e|puts e*''};puts
answer=''
phase1.split('').each_slice(2).each_with_index{|e,i|
	#puts e.join
	#answer+=matrix[e[0]][e[1]]||"[#{e.join}]"
	answer+=matrix[e[1]][e[0]] #bah! hineri!
}
puts answer
# nihonsainantannoshimahadoko => 沖ノ鳥島
__END__
o asid
   h k
 lz tc
 brnm1
e234w5
67 89 