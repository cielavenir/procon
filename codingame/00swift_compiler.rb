#!/usr/bin/ruby
puts "//usr/bin/env xcrun swift $0 $@;exit"
puts "import CoreFoundation"
print "system(\"ruby -e '"
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	print l.gsub('"','\"').gsub("'",'\"')+';' if !l.start_with?('#')
}
puts "'\")"