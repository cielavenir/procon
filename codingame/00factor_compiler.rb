#!/usr/bin/ruby
ESC=DATA.read.strip
puts "USING: io.launcher kernel ;"
print "\"ruby -e \\\""
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	print l.gsub('"',ESC).gsub("'",ESC)+';' if !l.start_with?('#')
}
puts "\\\"\" run-process drop"
__END__
\\\\\\"