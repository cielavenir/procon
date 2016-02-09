#!/usr/bin/ruby
load File.expand_path(File.dirname(__FILE__))+'/000.rb'
ESC=DATA.read.strip
puts "USING: io.launcher kernel ;"
print "\"#{COMMAND} \\\"-e"
first=true
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	if !l.empty? && !l.start_with?('#')
		print ';' if !first
		first=false
		print l.gsub('"',ESC).gsub("'",ESC)
	end
}
print "\\\"\" run-process drop"
__END__
\\\\\\"