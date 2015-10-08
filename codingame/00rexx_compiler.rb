#!/usr/bin/ruby
puts "#!/usr/bin/env rexx"
print "\"ruby -e '"
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	print l.gsub("'",'"')+';' if !l.start_with?('#')
}
puts "'\""