#!/usr/bin/ruby
puts "        identification division."
puts "        program-id. cobol_compiler."
puts "        procedure division."
s=""
s<<"call \"system\" using \"ruby -e '"
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	s<<l.gsub('"','""').gsub("'",'""')+';' if !l.start_with?('#')
}
s<<"'\"."
a=s.chars.each_slice(72-8).with_index.map{|e,i|(i==0?'        ':'      -"')+e.join}
puts a
puts "        stop run."