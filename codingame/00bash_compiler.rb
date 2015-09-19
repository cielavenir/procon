#!/usr/bin/ruby
puts "#!/bin/bash"
print "ruby -e '"
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	print l.gsub("'",'"')+';' if !l.start_with?('#')
}
puts "'"