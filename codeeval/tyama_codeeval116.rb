#!/usr/bin/ruby
h={''=>' '}
DATA.each_with_index{|s,i|
	s.chomp.each_char.with_index{|e,j|
		h[i.downto(0).map{|k|j[k]==0?'.':'-'}*'']=e
	}
}
h.to_a.sort_by(&:last).each{|k,v| # meta-program for C++ version
	puts 'm["'+k+'"]='+v.ord.to_s+';' if v!='?'
}
=begin
puts $<.map{|e|
	e.chomp.split('  ').map{|f|f.split.map{|g|h[g]}*''}*' '
}
=end

# http://en.wikipedia.org/wiki/Morse_code#Alternative_display_of_more_common_characters_in_International_Morse_code
__END__
ET
IANM
SURWDKGO
HVF?LAPJBXCYZQ??
54?3???2??+????16=/?????7???8?90