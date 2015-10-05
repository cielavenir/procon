#!/usr/bin/ruby
puts "#!/usr/bin/env runghc"
puts "import System.Cmd"
print "main=system(\"ruby -e '"
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	print l.gsub('"','\"').gsub("'",'\"')+';' if !l.start_with?('#')
}
puts "'\")"