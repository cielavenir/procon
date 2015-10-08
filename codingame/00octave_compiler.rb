#!/usr/bin/ruby
puts "#!/usr/bin/env octave -q"
print "system(\"ruby -e '"
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	print l.gsub('"','\"').gsub("'",'\"')+';' if !l.start_with?('#')
}
puts "'\");"