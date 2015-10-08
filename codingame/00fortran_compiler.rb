#!/usr/bin/ruby
s=""
s<<"call system(\"ruby -e '"
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	s<<l.gsub('"','""').gsub("'",'""')+';' if !l.start_with?('#')
}
s<<"'\")"
a=s.chars.each_slice(132-2).with_index.map{|e,i|(i==0?' ':'&')+e.join+'&'}
a.last.chop!
puts a
puts "end"