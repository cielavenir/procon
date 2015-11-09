#!/usr/bin/ruby
puts ":-prompt(_,'')."
print "main:-shell(\"ruby -e '"
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	print l.gsub('"','\"').gsub("'",'\"')+';' if !l.start_with?('#')
}
puts "'\"),halt,!."
puts ":-initialization(main)."